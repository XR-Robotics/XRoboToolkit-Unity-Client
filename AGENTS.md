# XRoboToolkit development environment

## Project baseline

- Read `ProjectSettings/ProjectVersion.txt` and `Packages/manifest.json` before
  choosing APIs or tools. This project currently uses Unity 2022.3.16f1 and the
  local PICO Unity SDK 6.1.1 in PICO XR mode.
- Keep `com.bytedance.pico.xr` at `file:../PICO Unity SDK`. The old Integration
  SDK directory is an inactive migration fallback, not an active package.
- The enterprise ToB client is `tobservicelib-0.6.0-alpha.0.aar`. Its Android
  importer is enabled in `PICO Unity SDK/Enterprise/android`. The bundled
  `tobservicelib-release.aar` Android importer is disabled. Keep `tob_api-release.aar`
  enabled: it adapts the new enterprise wrapper to the existing alpha client.
  Keep only one ToB client to avoid duplicate Java classes.
- TRAE Editor for Unity provides AI-assisted code editing and project navigation.
  It is separate from Unity's `com.unity.ai.assistant` package.
- Official Unity Pipeline/MCP and the PICO Unity 6 initialization workflow require
  Unity 6. Do not run `/pico-unity-init`, install Pipeline/Assistant packages, change
  XR providers, or migrate this project as part of routine AI environment setup.
- Ask for a reviewed migration plan before changing the Unity or PICO SDK baseline.

## Development tools

- Run `python tools/ai/dev_environment.py check` for a read-only environment check.
- Use `python tools/ai/dev_environment.py pico -- <arguments>` for the installed
  official PICO CLI and `python tools/ai/dev_environment.py unity -- <arguments>`
  for the installed official Unity CLI.
- The wrapper always selects this repository as the working directory. It does
  not install tools implicitly.
- PICO development knowledge is available through `pico-dev-knowledge`. Verify
  every suggested API against the local SDK 6.1.1 declarations before using it.
- Load `.trae/skills/unity-project-development/SKILL.md` or
  `.trae/skills/pico-project-tools/SKILL.md` for the relevant operation.

## Project constraints

- Use English for code comments and commit messages. Prefer enums to magic numbers
  and keep classes focused on one responsibility.
- Protect PICO native calls with `PICO_XR`; keep `PXR_EnterprisePlugin` a native
  pass-through layer.
- Preserve Enterprise controller validity filtering, active-input checks, latest
  prediction mode, protocol fields and explicit numeric types.
- Keep project `PICO_XR` guards and the SDK's `ENABLE_PICO_XR_SDK` symbol.
  `EnterpriseControllerPoseSource` preserves Runtime-first controller acquisition.
- SDK 6.1 tracker/expand-device IDs are numeric and serialized as strings in the
  existing identifier fields. They are not the old alphanumeric hardware SNs.
- Preserve the application's `capturelib-0.0.7.aar` camera path. The SDK's
  `capturelib-release.aar` and `CameraRenderingPlugin.aar` importers are disabled
  because their camera JNI ABI conflicts with the application's capture library.
- Preserve user edits and collected data. Do not commit or push unless requested.
- Building APKs, installing apps, changing device settings, downloading additional
  toolchains, and launching an emulator require authorization for that operation.
  Read-only environment checks and device enumeration are allowed.
- Use `Docs/ai_development_environment.md` for setup and compatibility details.
- Use `pico_sdk_6_1_1_migration_report.md` for the migration evidence and limits.
