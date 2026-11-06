---
name: unity-project-development
description: Develop this XRoboToolkit Unity project with TRAE and Unity CLI. Use for Unity environment checks, script editing, and editor diagnostics in this repository.
---

# Unity project development

1. Read the root `AGENTS.md`, `ProjectSettings/ProjectVersion.txt`, and
   `Packages/manifest.json`. Resolve paths from this repository root.
2. Run `python tools/ai/dev_environment.py check` if tool availability is unknown.
   This command is read-only.
3. Use the TRAE Editor package declared in the manifest for script editing.
   Preserve Unity serialization, asset GUIDs, the local PICO SDK, and existing
   project settings.
4. Query installed editors with
   `python tools/ai/dev_environment.py unity -- editors --installed --json`.
   Select the editor matching `ProjectVersion.txt`; do not silently choose Unity 6.
5. Read command help before using an unfamiliar Unity CLI command. CLI version
   availability alone does not prove the editor's Pipeline or MCP is connected.
6. On Unity 2022, inspect and edit source directly. Official Unity Pipeline/MCP
   requires Unity 6; do not install it or invoke editor-control commands here.
7. For builds, app installation, editor/SDK migration, or new toolchain downloads,
   first verify authorization and the intended scope. Do not turn an environment
   check into a build.
8. Report the exact editor/CLI versions, executed checks, and unverified steps.
   Use `Docs/ai_development_environment.md` for setup details.
9. The active SDK is `com.bytedance.pico.xr` 6.1.1 at `file:../PICO Unity SDK`.
   `PicoSdkMigrationValidation.Run` validates resources, UI lifecycle and Android
   C# through `CompilePlayerScripts`; it does not build or install an APK.
