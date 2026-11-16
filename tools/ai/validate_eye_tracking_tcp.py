"""Compile TCP eye tracking with existing Unity references, without building an APK."""

import json
from pathlib import Path
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[2]
EDITOR = Path(r"C:\Program Files\Unity\Hub\Editor\2022.3.16f1\Editor")


def select_responses():
    selected = {}
    for response in sorted((ROOT / "Library/Bee/artifacts").glob("*/Assembly-CSharp.rsp"),
                           key=lambda path: path.stat().st_mtime):
        lines = response.read_text(encoding="utf-8-sig").splitlines()
        if not any("ByteDance.PICO.XR.ref.dll" in line for line in lines):
            continue
        if any("Unity.XR.PICO.ref.dll" in line or "PICO.TobSupport.ref.dll" in line
               for line in lines):
            continue
        defines = {symbol for line in lines if line.startswith("-define:")
                   for symbol in line.split(":", 1)[1].split(";")}
        kind = "Editor" if "UNITY_EDITOR" in defines else "Android" if "UNITY_ANDROID" in defines else None
        if kind and "PICO_XR" in defines and "ENABLE_PICO_XR_SDK" in defines:
            selected[kind] = response
    if set(selected) != {"Editor", "Android"}:
        raise RuntimeError("Current SDK 6.1.1 Editor and Android compilation references are required.")
    return selected


def compile_response(response, destination, extra_sources=(), replace_reference=None):
    lines = []
    for line in response.read_text(encoding="utf-8-sig").splitlines():
        if not line or line.startswith(("-out:", "-refout:", "-analyzer:", "/additionalfile:")):
            continue
        if replace_reference and line.startswith("-r:") and "/Assembly-CSharp.ref.dll" in line:
            line = f'-r:"{replace_reference}"'
        lines.append(line)
    for source in extra_sources:
        relative = source.relative_to(ROOT).as_posix()
        if not any(line.strip('"').replace("\\", "/") == relative for line in lines):
            lines.append(f'"{source}"')
    lines.append(f'-out:"{destination}"')
    rewritten = destination.with_suffix(".rsp")
    rewritten.write_text("\n".join(lines), encoding="utf-8")
    result = subprocess.run([
        str(EDITOR / "Data/NetCoreRuntime/dotnet.exe"),
        str(EDITOR / "Data/DotNetSdkRoslyn/csc.dll"),
        "@" + str(rewritten),
    ], cwd=ROOT, capture_output=True, text=True)
    print(result.stdout + result.stderr, end="")
    if result.returncode:
        raise RuntimeError(f"{destination.name} C# compilation failed")
    print(f"PASS: {destination.name} C# compilation ({response.parent.name})")


def run_managed_checks(response, runtime):
    destination = runtime.parent / "EyeTrackingTcpChecks.dll"
    lines = [line for line in response.read_text(encoding="utf-8-sig").splitlines()
             if line.startswith(("-r:", "-define:", "-langversion:", "-nostdlib", "-noconfig"))]
    lines.extend([
        "-target:exe", f'-out:"{destination}"', f'-r:"{runtime}"',
        f'"{ROOT / "tools/ai/EyeTrackingTcpChecks.cs"}"',
    ])
    rewritten = destination.with_suffix(".rsp")
    rewritten.write_text("\n".join(lines), encoding="utf-8")
    compiler = subprocess.run([
        str(EDITOR / "Data/NetCoreRuntime/dotnet.exe"),
        str(EDITOR / "Data/DotNetSdkRoslyn/csc.dll"), "@" + str(rewritten),
    ], cwd=ROOT, capture_output=True, text=True)
    print(compiler.stdout + compiler.stderr, end="")
    if compiler.returncode:
        raise RuntimeError("Managed EyeTracking TCP check compilation failed.")
    destination.with_suffix(".runtimeconfig.json").write_text(json.dumps({
        "runtimeOptions": {"tfm": "net6.0",
                           "framework": {"name": "Microsoft.NETCore.App", "version": "6.0.21"}}
    }), encoding="utf-8")
    result = subprocess.run([
        str(EDITOR / "Data/NetCoreRuntime/dotnet.exe"), str(destination),
        str(ROOT / "Library/ScriptAssemblies"), str(EDITOR / "Data/Managed/UnityEngine"),
        str(EDITOR / "Data/Managed"),
    ], cwd=ROOT, capture_output=True, text=True, timeout=30)
    print(result.stdout + result.stderr, end="")
    if result.returncode:
        raise RuntimeError("Managed EyeTracking TCP checks failed.")


def main():
    version = (ROOT / "ProjectSettings/ProjectVersion.txt").read_text()
    manifest = json.loads((ROOT / "Packages/manifest.json").read_text())["dependencies"]
    sdk = json.loads((ROOT / "PICO Unity SDK/package.json").read_text())
    if ("m_EditorVersion: 2022.3.16f1" not in version or
            manifest.get("com.bytedance.pico.xr") != "file:../PICO Unity SDK" or
            sdk["version"] != "6.1.1"):
        raise RuntimeError("This validator requires Unity 2022.3.16f1 and the active local PICO SDK 6.1.1.")
    with tempfile.TemporaryDirectory(prefix="xrobotoolkit_eye_tcp_") as directory:
        outputs = Path(directory)
        for kind, response in select_responses().items():
            runtime = outputs / kind / "Assembly-CSharp.dll"
            runtime.parent.mkdir()
            compile_response(response, runtime, [ROOT / "Assets/Scripts/EyeTrackingData.cs"])
            if kind == "Editor":
                compile_response(response.parent / "Assembly-CSharp-Editor.rsp",
                                 runtime.parent / "Assembly-CSharp-Editor.dll",
                                 [ROOT / "Assets/Editor/EyeTrackingTcpValidation.cs"],
                                 replace_reference=runtime)
                run_managed_checks(response, runtime)
    print("No APK generated. Run Tools/XRoboToolkit/Validate Eye Tracking TCP for Editor runtime checks.")


if __name__ == "__main__":
    main()
