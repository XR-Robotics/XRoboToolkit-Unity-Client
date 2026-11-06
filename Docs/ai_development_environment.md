# AI development environment

This setup adds TRAE Editor for Unity, project-specific AI instructions, and
entry points for the existing official Unity and PICO CLIs.

## Versions and compatibility

| Component | Verified version or requirement |
| --- | --- |
| Project Unity Editor | 2022.3.16f1 |
| Local PICO Unity SDK | 6.1.1; `com.bytedance.pico.xr`, PICO XR mode |
| TRAE Editor for Unity | 1.0.2; Unity 2021.3 or newer |
| TRAE package commit | `1b1b02717ee1c8427a3d25c7ceb8d3882d856f4b` |
| Unity CLI on this machine | 1.0.0-beta.13 |
| PICO CLI on this machine | 0.6.0, public distribution |
| Node.js on this machine | 22.14.0; PICO CLI requires 20 or newer |
| Installed PICO knowledge | Unity knowledge bundle 6.1; verify APIs against local SDK 6.1.1 |

`Packages/manifest.json` pins `com.bytedance.ide.trae` to the verified official
package commit. Unity Package Manager resolves this dependency when the project
is opened. The latest 1.0.6 commit was rejected by an actual Unity 2022.3.16f1
compile check because it calls `PackageInfo.FindForPackageName`, which this
editor version does not expose. The pinned 1.0.2 commit predates that call.
All 31 editor source files from the pinned commit were compiled successfully
with the Unity 2022.3.16f1 C# compiler and the same Unity assembly references.
The SDK migration validation on 2026-11-05 also loaded the pinned TRAE package
in the actual Unity 2022.3.16f1 Editor.

TRAE integration supports AI-assisted script editing and Unity project navigation.
It does not provide Unity's in-editor AI Assistant or live scene-control MCP.
Official Unity Pipeline/MCP and the PICO Unity AI initialization workflow require
Unity 6 or newer. Changing the editor baseline needs a separate migration review.

## Use the tools

Run from the repository root:

```powershell
python tools/ai/dev_environment.py check
python tools/ai/dev_environment.py pico -- --version
python tools/ai/dev_environment.py pico -- device list
python tools/ai/dev_environment.py pico -- knowledge doctor --format json
python tools/ai/dev_environment.py unity -- --version
python tools/ai/dev_environment.py unity -- editors --installed --json
```

The wrapper selects this repository as the working directory and invokes the
already installed tools. `check` only reads files and prints CLI versions.
Tool-forwarding commands perform the operation passed to them; review commands
that build, install applications, or write to devices before using them.

The current machine already has C#, C# Dev Kit, the Unity extension, and PICO
Unity Assistant installed in TRAE CN. No additional IDE extension is needed.

## Connect PICO knowledge to TRAE

`.trae/mcp.windows.json` is a machine-specific import configuration. It starts the
official PICO knowledge service through the Python wrapper and the existing
knowledge cache.

Use TRAE's MCP management panel to import the JSON or add its stdio server.
Direct agent edits to `.trae/mcp.json` are restricted by TRAE. A manually
registered server uses the wrapper's repository path even when TRAE stores
the registration in its user settings. Confirm `pico-dev-knowledge` is connected
before claiming knowledge-tool availability. Start a new conversation after
adding project skills and rules.

On this machine, the server was registered through the MCP management panel and
showed a connected status with `query_graph`, `graph_stats`, and
`switch_workspace` tools. The registration is stored by TRAE in user settings;
the command explicitly selects this repository through its wrapper path.

On another machine, check the installed CLIs and Python, then generate a new
configuration at a new path:

```powershell
python tools/ai/dev_environment.py export-mcp ".trae/mcp.generated.json"
```

Review and import the generated file in TRAE's MCP management panel.
The export command refuses to overwrite an existing file. The CLI wrapper also
accepts `UNITY_CLI_PATH` and `PICO_CLI_ENTRYPOINT` when executables are installed
outside the standard locations. `PICO_CLI_ENTRYPOINT` must point to the official
package's JavaScript executable.

## Open the project in Unity

Use Unity 2022.3.16f1. After Package Manager finishes:

1. Confirm **TRAE Editor 1.0.2** is installed.
2. In **Edit > Preferences > External Tools**, select **Trae CN** as the external
   script editor. If automatic discovery misses this machine's custom install,
   browse to `D:\Trae CN\Trae CN.exe`.
3. Double-click a script to verify navigation to TRAE.
4. Confirm that the Unity Console has no new compilation errors.

Keep `com.bytedance.pico.xr` at `file:../PICO Unity SDK`. The old Integration
directory remains inactive for migration fallback. Do not run `/pico-unity-init` against this
existing project or install Unity 6-only packages to satisfy a generic doctor.

## Diagnostic limits

The CLI versions and the existing PICO knowledge service were checked without
building an APK or launching an emulator. `pico-cli knowledge doctor --format json`
confirmed that Graphify 0.5.9 can serve the installed Unity knowledge.

The 2026-11-05 SDK migration completed actual Editor import, resource/UI checks,
and Android C# compilation. `PicoSdkMigrationValidation.Run` ran 30 migration
checks and the existing eye gaze entry ran 15 checks. The Unity process exited
with code 0. Sandbox restrictions on Unity Hub, metrics, logging and shared
caches can still cause the shell tool to report a nonzero result; inspect the
Unity log and generated validation result rather than treating the launcher
status alone as the Editor result.

Use **Tools > XRoboToolkit > Validate PICO SDK Migration** or the existing CLI
wrapper to run `PicoSdkMigrationValidation.Run`. This compiles Android C# using
`PlayerBuildInterface.CompilePlayerScripts` without Gradle, IL2CPP, APK packaging,
or device installation. Results are under `Logs/pico-sdk-6.1.1-validation`.
Keyboard/pointer interaction in Play mode, device tracking and camera capture
remain separate runtime checks. See the root migration report for compatibility
changes and outstanding Project Validation prompts.

The broader PICO doctor reports incomplete legacy Cursor project context and
optional profiling dependencies. These do not prove that the CLI or knowledge
service is unavailable. This setup adds TRAE-specific project instructions;
it does not repair another agent's global plugin registration or install
profiling dependencies.

## Official sources

- [TRAE Editor for Unity](https://docs.trae.cn/ide_trae-editor-for-unity-tutorial)
- [TRAE project skills](https://docs.trae.cn/ide_skills)
- [PICO CLI setup](https://developer.picoxr.com/document/pico-cli/quickstart-common/)
- [PICO Unity workflow and Unity 6 requirement](https://developer.picoxr.com/document/pico-cli/quickstart-unity/)
- [Unity CLI and Pipeline compatibility](https://docs.unity.com/en-us/unity-cli/replace-mcp-server-unity-cli)
