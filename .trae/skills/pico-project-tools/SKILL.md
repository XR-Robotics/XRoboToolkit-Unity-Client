---
name: pico-project-tools
description: Use PICO CLI and PICO knowledge for this Unity project. Use for PICO device enumeration, log capture, data retrieval, SDK lookup, and environment diagnostics.
---

# PICO project tools

1. Read `AGENTS.md` and `PICO Unity SDK/package.json` from the project
   root. Use the project's installed SDK version when checking APIs.
2. Use `python tools/ai/dev_environment.py pico -- <arguments>` to invoke the
   existing official `@picoxr/pico-cli` package. This avoids PowerShell shim
   restrictions and pins the working directory to this repository.
3. Start with the smallest relevant read-only command:
   - `device list --help`, then `device list` to inspect connected devices.
   - `knowledge doctor --format json` to verify knowledge-server readiness.
   - `doctor --platform unity --format json` for a broader environment diagnosis.
4. Read subcommand help before log capture, file retrieval, or app operations.
   If multiple devices are visible, resolve the intended target before operating
   on it. Keep collected data intact and select an explicit output path.
5. Query `pico-dev-knowledge` when the MCP is connected. Otherwise use the local SDK
   declarations and official documentation. Never claim MCP access from the
   presence of a JSON configuration alone.
6. Validate retrieved methods, types, and platform requirements against local
   SDK 6.1.1. Preserve the selected PICO XR mode and the alpha enterprise client.
7. Do not initialize a new Unity/Spatial project, replace the SDK, or install
   Unity 6 to repair a generic doctor warning. This is an existing Unity 2022
   enterprise tracking client.
8. Verify authorization before app installs, device writes, emulator launches,
   profiling-dependency downloads, or builds. Distinguish optional tooling
   warnings from failures that block the requested operation.
9. Preserve `PICO_XR` guards, native pass-through boundaries, controller validity
   filtering, active-input checks, and the enterprise wire protocol.
