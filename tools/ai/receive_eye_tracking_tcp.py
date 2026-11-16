"""Receive and inspect XRoboToolkit Tracking packets using only Python's standard library."""

import argparse
from collections import Counter
import json
import math
from pathlib import Path
import socket
import struct
import time

MAX_BODY_BYTES = 1024 * 1024


class PacketReader:
    def __init__(self):
        self.buffer = bytearray()

    def feed(self, chunk):
        self.buffer.extend(chunk)
        packets = []
        while len(self.buffer) >= 6:
            if self.buffer[0] != 0x3F:
                raise ValueError("Expected frame header 0x3F")
            length = struct.unpack_from("<I", self.buffer, 2)[0]
            if length > MAX_BODY_BYTES:
                raise ValueError("Packet exceeds 1 MiB receiver limit")
            size = 15 + length
            if len(self.buffer) < size:
                break
            if self.buffer[size - 1] != 0xA5:
                raise ValueError("Expected frame trailer 0xA5")
            packets.append((self.buffer[1], bytes(self.buffer[6:6 + length])))
            del self.buffer[:size]
        return packets


def vector(value):
    return (isinstance(value, list) and len(value) == 3 and
            all(type(item) in (int, float) and math.isfinite(item) for item in value))


def check_eye(eye):
    if not isinstance(eye, dict):
        return ["EyeTracking must be an object"]
    errors = []
    for key in ("schemaVersion", "sampleSeq", "timeStampNs", "status", "sdkResult"):
        if type(eye.get(key)) is not int:
            errors.append(f"{key} must be an integer")
    if eye.get("schemaVersion") != 1:
        errors.append("Unsupported schemaVersion")
    for key in ("hasPose", "hasHit", "isSimulated"):
        if type(eye.get(key)) is not bool:
            errors.append(f"{key} must be a Boolean")
    for key in ("trackingState", "sampleFailure"):
        if not isinstance(eye.get(key), str):
            errors.append(f"{key} must be a string")
    for key in ("origin", "direction"):
        if not vector(eye.get(key)):
            errors.append(f"{key} must contain three finite numbers")
    if eye.get("coordinateSpace") != "unity_world" or eye.get("positionUnit") != "m":
        errors.append("Expected unity_world coordinates in meters")
    if eye.get("hasPose") is True and vector(eye.get("direction")):
        norm = math.sqrt(sum(item * item for item in eye["direction"]))
        if abs(norm - 1.0) > 0.01:
            errors.append(f"Direction is not normalized: length={norm:.6f}")
    if eye.get("hasPose") is False:
        if eye.get("origin") != [0, 0, 0] or eye.get("direction") != [0, 0, 0]:
            errors.append("Invalid pose still contains a ray")
        if eye.get("hasHit") is not False:
            errors.append("Invalid pose still reports a hit")
    if eye.get("hasHit") is True:
        hit = eye.get("hit")
        if not isinstance(hit, dict):
            errors.append("hasHit=true requires a hit object")
        else:
            if hit.get("kind") not in ("Collider", "WorldSpaceUI"):
                errors.append("Unknown hit kind")
            if not vector(hit.get("point")) or not vector(hit.get("normal")):
                errors.append("Hit point/normal must contain three finite numbers")
            distance = hit.get("distance")
            if type(distance) not in (int, float) or not math.isfinite(distance) or distance < 0:
                errors.append("Hit distance must be finite and nonnegative")
            if hit.get("target") is not None and not isinstance(hit["target"], str):
                errors.append("Hit target must be a string or null")
    elif "hit" in eye:
        errors.append("hasHit=false still contains a hit object")
    return errors


class Monitor:
    def __init__(self, output=None):
        self.output = output
        self.total = Counter()
        self.window = Counter()
        self.connection = 0
        self.reset_peer()
        self.last_report = time.monotonic()

    def reset_peer(self):
        self.last_eye = None
        self.last_seq = None
        self.last_new_eye = None
        self.last_state = None

    def count(self, key):
        self.total[key] += 1
        self.window[key] += 1

    def issue(self, message):
        self.count("errors")
        if self.window["errors"] <= 3:
            print("ERROR:", message, flush=True)

    def packet(self, command, body):
        self.count("packets")
        if command in (0x19, 0x6C):
            print(f"Handshake 0x{command:02X}: {body.decode('utf-8')}", flush=True)
            return
        if command != 0x6D:
            return
        try:
            envelope = json.loads(body.decode("utf-8"))
            if envelope.get("functionName") != "Tracking":
                return
            tracking = json.loads(envelope["value"])
            self.count("tracking")
            eye = tracking.get("EyeTracking")
            if self.output is not None:
                self.output.write(json.dumps({
                    "receivedAtNs": time.time_ns(), "connection": self.connection,
                    "trackingTimeStampNs": tracking.get("timeStampNs"), "EyeTracking": eye,
                }, ensure_ascii=False, allow_nan=False) + "\n")
            if eye is None:
                self.count("missing")
                self.last_eye = None
                self.last_seq = None
                self.last_new_eye = None
                self.state("EyeTracking absent")
                return
            errors = check_eye(eye)
            if errors:
                self.issue("; ".join(errors))
                return
            self.last_eye = eye
            self.state(f'{eye["trackingState"]} pose={eye["hasPose"]} '
                       f'hit={eye["hasHit"]} simulated={eye["isSimulated"]} '
                       f'sdk={eye["sdkResult"]} failure={eye["sampleFailure"]}')
            if eye["sampleSeq"] == self.last_seq:
                self.count("repeated")
                return
            if self.last_seq is not None and eye["sampleSeq"] < self.last_seq:
                self.issue("sampleSeq moved backwards within the connection")
            self.last_seq = eye["sampleSeq"]
            self.last_new_eye = time.monotonic()
            self.count("eye_new")
            self.count("valid" if eye["hasPose"] else "invalid")
            if self.total["eye_new"] == 1:
                print("First EyeTracking:", json.dumps(eye, ensure_ascii=False), flush=True)
        except (ValueError, KeyError, TypeError, AttributeError, UnicodeError) as error:
            self.issue(str(error))

    def state(self, description):
        if description != self.last_state:
            print("STATE:", description, flush=True)
            self.last_state = description

    def report(self, force=False):
        now = time.monotonic()
        elapsed = now - self.last_report
        if elapsed < 1.0 and not force:
            return
        elapsed = max(elapsed, 0.001)
        new = self.window["eye_new"]
        valid = f'{100 * self.window["valid"] / new:.1f}%' if new else "n/a"
        age = f"{now - self.last_new_eye:.2f}s" if self.last_new_eye is not None else "n/a"
        eye = self.last_eye
        ray = (f' seq={eye["sampleSeq"]} origin={eye["origin"]} direction={eye["direction"]}'
               if eye is not None else "")
        print(f'tracking={self.window["tracking"] / elapsed:.1f}/s '
              f'eyeNew={new / elapsed:.1f}/s valid={valid} '
              f'repeat={self.window["repeated"]} absent={self.window["missing"]} '
              f'errors={self.window["errors"]} lastNewAge={age}{ray}', flush=True)
        if self.output is not None:
            self.output.flush()
        self.window.clear()
        self.last_report = now


def serve(args):
    output = None
    if args.output:
        path = Path(args.output)
        if not path.parent.is_dir():
            raise ValueError(f"Output directory does not exist: {path.parent}")
        output = path.open("x", encoding="utf-8")
    monitor = Monitor(output)
    started = time.monotonic()
    running = lambda: args.duration == 0 or time.monotonic() - started < args.duration
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server:
            server.bind((args.host, args.port))
            server.listen(1)
            server.settimeout(0.25)
            print(f"Listening on {args.host}:{args.port}; start the headset app. Ctrl+C stops.", flush=True)
            while running():
                try:
                    peer, address = server.accept()
                except socket.timeout:
                    monitor.report()
                    continue
                monitor.connection += 1
                monitor.reset_peer()
                reader = PacketReader()
                print(f"CONNECTED #{monitor.connection}: {address[0]}:{address[1]}", flush=True)
                with peer:
                    peer.settimeout(0.25)
                    while running():
                        try:
                            chunk = peer.recv(65536)
                            if not chunk:
                                if reader.buffer:
                                    monitor.issue("Connection closed in the middle of a frame")
                                print("DISCONNECTED", flush=True)
                                break
                            for command, body in reader.feed(chunk):
                                monitor.packet(command, body)
                        except socket.timeout:
                            pass
                        except (OSError, ValueError) as error:
                            monitor.issue(str(error))
                            break
                        monitor.report()
                monitor.reset_peer()
    except KeyboardInterrupt:
        pass
    finally:
        monitor.report(force=True)
        print("TOTAL:", dict(monitor.total), flush=True)
        if not monitor.total["eye_new"]:
            print("No validated EyeTracking samples received.", flush=True)
        if output is not None:
            output.close()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--host", default="0.0.0.0", help="IPv4 address to listen on")
    parser.add_argument("--port", type=int, default=63901)
    parser.add_argument("--duration", type=float, default=0, help="Stop after N seconds; 0 waits until Ctrl+C")
    parser.add_argument("--output", help="Save received Tracking eye fields as JSONL; existing files are preserved")
    args = parser.parse_args()
    if args.duration < 0 or not 1 <= args.port <= 65535:
        parser.error("Duration must be nonnegative and port must be between 1 and 65535")
    try:
        serve(args)
    except (OSError, ValueError) as error:
        parser.exit(1, f"Receiver failed: {error}\n")


if __name__ == "__main__":
    main()
