#!/usr/bin/env python3
"""Inspect and use this project's Unity and PICO development tools."""

from __future__ import annotations

import argparse
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import sys


PROJECT_ROOT = Path(__file__).resolve().parents[2]
TRAE_PACKAGE = "com.bytedance.ide.trae"
PICO_PACKAGE = "com.bytedance.pico.xr"


def pico_sdk_package() -> tuple[Path, dict]:
    dependencies = json.loads(
        (PROJECT_ROOT / "Packages/manifest.json").read_text(encoding="utf-8")
    )["dependencies"]
    reference = dependencies.get(PICO_PACKAGE, "")
    if not reference.startswith("file:"):
        raise RuntimeError(f"{PICO_PACKAGE} must reference a fixed local SDK package.")
    directory = (PROJECT_ROOT / "Packages" / reference[5:]).resolve()
    package = json.loads((directory / "package.json").read_text(encoding="utf-8"))
    if package.get("name") != PICO_PACKAGE:
        raise RuntimeError("The local PICO dependency has an unexpected package name.")
    if "com.unity.xr.picoxr" in dependencies:
        raise RuntimeError("Old and new PICO XR packages must not be active together.")
    return directory, package


def unity_version() -> str:
    text = (PROJECT_ROOT / "ProjectSettings/ProjectVersion.txt").read_text(
        encoding="utf-8"
    )
    match = re.search(r"^m_EditorVersion:\s*(\S+)", text, re.MULTILINE)
    if not match:
        raise RuntimeError("ProjectVersion.txt has no Unity editor version.")
    return match.group(1)


def find_unity_cli() -> list[str]:
    override = os.environ.get("UNITY_CLI_PATH")
    if override:
        candidate = Path(override).expanduser()
        if not candidate.is_file():
            raise RuntimeError("UNITY_CLI_PATH must point to the Unity CLI executable.")
        return [str(candidate)]
    if os.name == "nt":
        local_app_data = os.environ.get("LOCALAPPDATA")
        if local_app_data:
            candidate = Path(local_app_data) / "Unity/bin/unity.exe"
            if candidate.is_file():
                return [str(candidate)]
    command = shutil.which("unity")
    if command:
        return [command]
    raise RuntimeError("Unity CLI was not found. Set UNITY_CLI_PATH or install Unity CLI.")


def find_pico_cli() -> list[str]:
    node = shutil.which("node")
    if not node:
        raise RuntimeError("Node.js 20 or newer is required by PICO CLI.")
    override = os.environ.get("PICO_CLI_ENTRYPOINT")
    candidates = [Path(override).expanduser()] if override else []
    if os.name == "nt" and os.environ.get("APPDATA"):
        candidates.append(
            Path(os.environ["APPDATA"]) / "npm/node_modules/@picoxr/pico-cli"
        )
    command = shutil.which("pico-cli")
    if command:
        executable = Path(command)
        if executable.is_symlink():
            candidates.append(executable.resolve())
        candidates.extend(
            [
                executable.parent / "node_modules/@picoxr/pico-cli",
                executable.parent.parent / "lib/node_modules/@picoxr/pico-cli",
            ]
        )
    for candidate in candidates:
        if candidate.is_file() and candidate.suffix in {".js", ".mjs", ".cjs"}:
            return [node, str(candidate)]
        manifest = candidate / "package.json"
        if not manifest.is_file():
            continue
        package = json.loads(manifest.read_text(encoding="utf-8"))
        if package.get("name") != "@picoxr/pico-cli":
            continue
        binary = package.get("bin")
        entry = binary if isinstance(binary, str) else (binary or {}).get("pico-cli")
        if entry and (candidate / entry).is_file():
            return [node, str(candidate / entry)]
    raise RuntimeError(
        "PICO CLI was not found. Install @picoxr/pico-cli or set PICO_CLI_ENTRYPOINT "
        "to its JavaScript entry point."
    )


def run_tool(command: list[str], arguments: list[str]) -> int:
    # Invoke Node directly for PICO CLI to avoid PowerShell shim restrictions.
    return subprocess.call(command + arguments, cwd=PROJECT_ROOT)


def inspect_environment() -> int:
    version = unity_version()
    dependencies = json.loads(
        (PROJECT_ROOT / "Packages/manifest.json").read_text(encoding="utf-8")
    )["dependencies"]
    sdk_directory, pico_sdk = pico_sdk_package()
    print(f"Project: {PROJECT_ROOT}", flush=True)
    print(f"Unity Editor: {version}", flush=True)
    print(f"PICO Unity SDK: {pico_sdk['version']} ({sdk_directory})", flush=True)
    print(f"TRAE editor package: {dependencies.get(TRAE_PACKAGE, 'missing')}", flush=True)
    failed = TRAE_PACKAGE not in dependencies
    for name, finder in (("Unity CLI", find_unity_cli), ("PICO CLI", find_pico_cli)):
        try:
            command = finder()
            print(f"{name}: {command}", flush=True)
            failed |= run_tool(command, ["--version"]) != 0
        except (OSError, RuntimeError) as error:
            failed = True
            print(f"{name}: {error}", file=sys.stderr)
    supports_pipeline = int(version.split(".", 1)[0]) >= 6000
    print(
        "Official Unity Pipeline/MCP: "
        + ("version prerequisite met; connection still needs verification"
           if supports_pipeline else "requires Unity 6; unavailable in this project"),
        flush=True,
    )
    print("Check does not build, install packages, launch an editor, or modify a device.")
    return int(failed)


def export_mcp(output: Path) -> int:
    if output.exists():
        raise RuntimeError(f"Output already exists: {output}")
    if not output.parent.is_dir():
        raise RuntimeError(f"Output directory does not exist: {output.parent}")
    # A local process uses the existing official CLI and existing knowledge cache.
    find_pico_cli()
    config = {
        "mcpServers": {
            "pico-dev-knowledge": {
                "command": str(Path(sys.executable).resolve()),
                "args": [str(Path(__file__).resolve()), "knowledge-mcp"],
            }
        }
    }
    output.write_text(json.dumps(config, indent=2) + "\n", encoding="utf-8")
    print(output)
    return 0


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    commands = parser.add_subparsers(dest="command", required=True)
    commands.add_parser("check", help="Read-only check of project versions and CLI availability")
    for name in ("pico", "unity"):
        tool = commands.add_parser(name, help=f"Forward arguments to the existing {name} CLI")
        tool.add_argument("arguments", nargs=argparse.REMAINDER)
    commands.add_parser("knowledge-mcp", help="Start the official PICO knowledge MCP over stdio")
    export = commands.add_parser("export-mcp", help="Write a machine-specific MCP import file")
    export.add_argument("output", type=Path)
    args = parser.parse_args()
    if args.command == "check":
        return inspect_environment()
    if args.command == "export-mcp":
        return export_mcp(args.output.resolve())
    if args.command == "knowledge-mcp":
        return run_tool(find_pico_cli(), ["knowledge", "server"])
    arguments = args.arguments
    if arguments[:1] == ["--"]:
        arguments = arguments[1:]
    finder = find_pico_cli if args.command == "pico" else find_unity_cli
    return run_tool(finder(), arguments)


if __name__ == "__main__":
    try:
        sys.exit(main())
    except (OSError, RuntimeError, ValueError) as error:
        print(f"Development environment error: {error}", file=sys.stderr)
        sys.exit(1)
