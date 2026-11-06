---
alwaysApply: true
---

Follow the project baseline and tool instructions in `AGENTS.md`.

Use Unity 2022.3.16f1 APIs and PICO Unity SDK 6.1.1 in PICO XR mode,
referenced by `com.bytedance.pico.xr` at `file:../PICO Unity SDK`.
TRAE Editor for Unity supports this editor version. Official Unity Pipeline/MCP
requires Unity 6 and must not be assumed available here.

Use `tools/ai/dev_environment.py` to select the existing CLI tools and this
project's working directory. Match knowledge-base suggestions against local
SDK declarations before changing code.

Review a migration plan with the user before upgrading the editor, replacing the
PICO SDK, or running a new-project initialization workflow. Obtain authorization
before builds, device app installation, or additional toolchain downloads.
Write code comments and commit messages in English.
