#!/usr/bin/env bash
set -euo pipefail

PACKAGE="${PICO_APP_PACKAGE:-}"
ADB="${ADB:-adb}"
STAMP="$(date +%Y%m%d-%H%M%S)"
OUT_DIR="${1:-/tmp/g1_wuji_pico_crash_probe_${STAMP}}"

mkdir -p "$OUT_DIR"

"$ADB" start-server >/dev/null
"$ADB" get-state >/dev/null

if [[ -z "$PACKAGE" ]]; then
  INSTALLED_PACKAGES="$("$ADB" shell "pm list packages 'com.xrobotoolkit.client'" 2>/dev/null | tr -d '\r' || true)"
  if grep -qx "package:com.xrobotoolkit.client.voicebeta" <<<"$INSTALLED_PACKAGES"; then
    PACKAGE="com.xrobotoolkit.client.voicebeta"
  elif grep -qx "package:com.xrobotoolkit.client" <<<"$INSTALLED_PACKAGES"; then
    PACKAGE="com.xrobotoolkit.client"
  else
    PACKAGE="com.xrobotoolkit.client"
  fi
fi

REMOTE_PROBE_DIR="/sdcard/Android/data/${PACKAGE}/files/g1_wuji_crash_probe"

"$ADB" devices -l >"$OUT_DIR/adb_devices.txt" 2>&1 || true
"$ADB" shell getprop ro.product.model >"$OUT_DIR/device_model.txt" 2>&1 || true
"$ADB" shell getprop ro.build.fingerprint >"$OUT_DIR/build_fingerprint.txt" 2>&1 || true
"$ADB" shell pidof "$PACKAGE" >"$OUT_DIR/pidof.txt" 2>&1 || true

"$ADB" logcat -d -v threadtime >"$OUT_DIR/logcat_threadtime.txt" 2>&1 || true

"$ADB" shell "ls -la '$REMOTE_PROBE_DIR'" >"$OUT_DIR/probe_listing.txt" 2>&1 || true
if ! "$ADB" pull "$REMOTE_PROBE_DIR" "$OUT_DIR/probe" >"$OUT_DIR/probe_pull.txt" 2>&1; then
  mkdir -p "$OUT_DIR/probe_run_as"
  "$ADB" exec-out run-as "$PACKAGE" sh -c \
    "cd files 2>/dev/null && tar -cf - g1_wuji_crash_probe 2>/dev/null" \
    >"$OUT_DIR/probe_run_as.tar" 2>"$OUT_DIR/probe_run_as_stderr.txt" || true
  if [[ -s "$OUT_DIR/probe_run_as.tar" ]]; then
    tar -xf "$OUT_DIR/probe_run_as.tar" -C "$OUT_DIR/probe_run_as" || true
  fi
fi

"$ADB" shell "ls -lt /data/tombstones 2>&1 | head -40" \
  >"$OUT_DIR/tombstones_listing.txt" 2>&1 || true
"$ADB" shell "ls -lt /data/anr 2>&1 | head -40" \
  >"$OUT_DIR/anr_listing.txt" 2>&1 || true
"$ADB" shell "dumpsys activity processes 2>&1 | grep -i -A 20 -B 10 '$PACKAGE'" \
  >"$OUT_DIR/activity_processes_package.txt" 2>&1 || true
"$ADB" shell "dumpsys dropbox --print 2>&1 | grep -i -A 60 -B 10 '$PACKAGE'" \
  >"$OUT_DIR/dropbox_package.txt" 2>&1 || true

cat >"$OUT_DIR/README.txt" <<EOF
G1-Wuji Pico crash probe export

Package: $PACKAGE
Probe dir attempted: $REMOTE_PROBE_DIR

Important files:
- probe/g1_wuji_crash_probe/breadcrumbs.jsonl or probe_run_as/g1_wuji_crash_probe/breadcrumbs.jsonl
- probe/g1_wuji_crash_probe/active_session.json
- probe/g1_wuji_crash_probe/last_exit.json
- logcat_threadtime.txt
- tombstones_listing.txt, anr_listing.txt, dropbox_package.txt

If tombstone/ANR files show Permission denied, that is expected on non-root Pico firmware.
Use logcat plus last_exit.json and breadcrumbs.jsonl as the first debugging surface.
EOF

echo "$OUT_DIR"
