"""Compile eye gaze scripts with existing Unity 2022 references; never build an APK."""

import json
import argparse
from pathlib import Path
import re
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[2]
EDITOR = Path(r"C:\Program Files\Unity\Hub\Editor\2022.3.16f1\Editor")
SOURCES = sorted((ROOT / "Assets/Scripts/EyeGaze").glob("*.cs"))


def compile_scripts(original, output_dir):
    cache = original.parent
    configuration = cache.name
    lines = []
    for line in original.read_text(encoding="utf-8-sig").splitlines():
        if not line.startswith(("-", "/")):
            continue
        if line.startswith(("-out:", "-refout:", "-analyzer:", "/additionalfile:", "/unsafe")):
            continue
        lines.append(line)
    runtime = cache / "ByteDance.PICO.XR.ref.dll"
    if not runtime.is_file() or not any("ByteDance.PICO.XR.ref.dll" in line for line in lines):
        raise RuntimeError("Regenerate Unity compilation references with the active 6.1.1 package.")
    if any("Unity.XR.PICO.ref.dll" in line or "PICO.TobSupport.ref.dll" in line for line in lines):
        raise RuntimeError("The compilation response still references the old SDK.")
    lines.extend(["/unsafe-", f'-out:"{output_dir / (configuration + ".dll")}"'])
    lines.extend(f'"{path}"' for path in SOURCES)
    response = output_dir / (configuration + ".rsp")
    response.write_text("\n".join(lines), encoding="utf-8")
    result = subprocess.run([
        str(EDITOR / "Data/NetCoreRuntime/dotnet.exe"),
        str(EDITOR / "Data/DotNetSdkRoslyn/csc.dll"),
        "@" + str(response),
    ], cwd=ROOT, capture_output=True, text=True)
    print(result.stdout + result.stderr, end="")
    if result.returncode:
        raise RuntimeError(f"{configuration} C# compilation failed")
    print(f"PASS: {configuration} C# compilation")
    if any("UNITY_EDITOR" in line for line in lines if line.startswith("-define:")):
        editor_lines = [line for line in lines if not line.startswith(('-out:', '"'))]
        editor_lines.extend([
            f'-r:"{output_dir / (configuration + ".dll")}"',
            f'-out:"{output_dir / "EyeGazeValidation.dll"}"',
            f'"{ROOT / "Assets/Editor/EyeGazeValidation.cs"}"',
        ])
        editor_response = output_dir / "EyeGazeValidation.rsp"
        editor_response.write_text("\n".join(editor_lines), encoding="utf-8")
        editor_result = subprocess.run([
            str(EDITOR / "Data/NetCoreRuntime/dotnet.exe"),
            str(EDITOR / "Data/DotNetSdkRoslyn/csc.dll"),
            "@" + str(editor_response),
        ], cwd=ROOT, capture_output=True, text=True)
        print(editor_result.stdout + editor_result.stderr, end="")
        if editor_result.returncode:
            raise RuntimeError("Eye gaze Editor validation entry compilation failed")
        print("PASS: Editor validation entry C# compilation")


def check_assets():
    prefab = ROOT / "Assets/InteractionTools/Prefabs/XR Origin (XR Rig).prefab"
    text = prefab.read_text(encoding="utf-8-sig")
    ids = re.findall(r"^--- !u!\d+ &(\d+)", text, re.MULTILINE)
    if len(ids) != len(set(ids)):
        raise RuntimeError("Duplicate prefab object IDs")
    for component, filename in [
        ("906000000000000101", "PicoEyeGazeSource"),
        ("906000000000000102", "EyeGazeRaycaster"),
        ("906000000000000103", "EyeGazeVisualizer"),
    ]:
        guid = re.search(r"^guid: (\w+)", (ROOT / f"Assets/Scripts/EyeGaze/{filename}.cs.meta")
                         .read_text(), re.MULTILINE).group(1)
        if f"guid: {guid}" not in text or f"- component: {{fileID: {component}}}" not in text:
            raise RuntimeError(f"Missing prefab component reference: {filename}")
    if "eyeTracking: 1" not in text:
        raise RuntimeError("PXR_Manager eye tracking is disabled")
    settings = (ROOT / "Assets/Resources/PXR_ProjectSetting.asset").read_text()
    if "eyeTracking: 1" not in settings:
        raise RuntimeError("PICO project eye tracking is disabled")
    assembly = json.loads((ROOT / "Assets/Scripts/EyeGaze/XRoboToolkit.EyeGaze.asmdef").read_text())
    if "ByteDance.PICO.XR" not in assembly["references"]:
        raise RuntimeError("Missing PICO runtime assembly reference")
    scene = (ROOT / "Assets/Main.unity").read_text(encoding="utf-8-sig")
    if "guid: dd642571209dae844a5e4c97fee0654b" not in scene:
        raise RuntimeError("Main scene does not reference the configured XR Rig")
    print("PASS: prefab GUIDs, IDs, SDK feature settings and Main scene wiring")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--assets-only", action="store_true",
                        help="Check wiring and active SDK without repeating compilation")
    args = parser.parse_args()
    version = (ROOT / "ProjectSettings/ProjectVersion.txt").read_text()
    if "m_EditorVersion: 2022.3.16f1" not in version:
        raise RuntimeError("This validation requires the project's Unity 2022.3.16f1 baseline")
    check_assets()
    manifest = json.loads((ROOT / "Packages/manifest.json").read_text())["dependencies"]
    if manifest.get("com.bytedance.pico.xr") != "file:../PICO Unity SDK" or "com.unity.xr.picoxr" in manifest:
        raise RuntimeError("The active SDK dependency is not the migrated local package")
    sdk = json.loads((ROOT / "PICO Unity SDK/package.json").read_text())
    if sdk["name"] != "com.bytedance.pico.xr" or sdk["version"] != "6.1.1":
        raise RuntimeError("The migrated package must be SDK 6.1.1")
    if args.assets_only:
        return
    responses = list((ROOT / "Library/Bee/artifacts").glob("*/XRoboToolkit.EyeGaze.rsp"))
    selected = {}
    for response in sorted(responses, key=lambda path: path.stat().st_mtime):
        text = response.read_text(encoding="utf-8-sig")
        if "ByteDance.PICO.XR.ref.dll" not in text:
            continue
        defines = set()
        for line in text.splitlines():
            if line.startswith("-define:"):
                defines.update(line.split(":", 1)[1].split(";"))
        kind = "Editor" if "UNITY_EDITOR" in defines else "Android" if "UNITY_ANDROID" in defines else None
        if kind:
            selected[kind] = response
    if set(selected) != {"Editor", "Android"}:
        raise RuntimeError("Run Unity Editor and Android C# compilation to regenerate both response files.")
    with tempfile.TemporaryDirectory(prefix="xrobotoolkit_eye_gaze_") as directory:
        for response in selected.values():
            compile_scripts(response, Path(directory))
    print("Standalone compilation only. Editor runtime and device tracking are separate checks.")


if __name__ == "__main__":
    main()
