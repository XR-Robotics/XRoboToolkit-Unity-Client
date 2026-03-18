import re
import os

# Source file path
INPUT_FILE = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List.md'
OUTPUT_FILE = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List_Report.md'

# Hardcoded translations based on file analysis
TRANSLATIONS = {
    "多语言测试器": "Localization Tester",
    "多语言测试": "Localization Test",
    "提示": "Tip",
    "场景中已存在一个多语言测试器": "A Localization Tester already exists in the scene",
    "好的": "OK",
    "平铺展示当前选中的UI": "Tile current selected UI",
    "获取所选物体": "Get selected object",
    "复制所选物体": "Duplicate selected object",
    "计算间距": "Calculate spacing",
    "使用物体的宽度作为初始间距": "Use object width as initial spacing",
    "设置一个缩放因子来调整间距": "Set a scale factor to adjust spacing",
    "在 X 轴上平移": "Translate on X axis",
    "辅助方法：获取物体的包围盒": "Helper method: Get object bounds",
    "如果找不到 Renderer 或 Collider，则返回默认包围盒": "If Renderer or Collider not found, return default bounds",
    "内部颜色": "Inner Color",
    "外部颜色": "Outer Color",
    "菲涅尔强度": "Fresnel Strength",
    "按下光照": "Press Light",
    "点击光照": "Click Light",
    "按压范围": "Press Range",
    "点击范围": "Click Range",
    "点击位置": "Click Position",
    "按压强度": "Press Intensity",
    "腕部渐变范围": "Wrist Fade Range",
    "总透明度": "Main Alpha",
    "透明消隐": "Fade In",
    "控制颜色衰减曲线的形状": "Controls the shape of the color attenuation curve",
    "控制缩放衰减曲线的形状": "Controls the shape of the scale attenuation curve",
    "确保alphaFactor在0到1之间": "Ensure alphaFactor is between 0 and 1",
    "请粘贴你的AppID": "Please paste your AppID",
    "APP ID 是应用的唯一标识": "APP ID is the unique identifier of the application",
    "推荐设置": "Recommended Settings",
    "推荐项目设置": "Recommended project settings",
    "设置目标平台为Android": "Set target platform to Android",
    "Unity Editor版本不小于": "Unity Editor version not less than",
    "设置屏幕方向为水平": "Set screen orientation to Landscape",
    "Android最小API不低于": "Android Min API not lower than",
    "稍后询问": "Ask later",
    "应用": "Apply",
    "开启高光时刻": "Enable Highlight Moments",
    "PXR SDK 设置": "PXR SDK Settings",
    "注意：PXR SDK 推荐项目配置": "Notice: PXR SDK Recommended Project Configuration",
    "切换至中文": "Switch to Chinese",
    "已应用": "Applied",
    "信息说明": "Information",
    "支持Unity版本：Unity2020.3.21及以上版本": "Supported Unity Version: Unity2020.3.21 and above",
    "获取最新版本的SDK:": "Get the latest version of SDK:",
    "配置": "Configuration",
    "当前": "Current",
    "推荐": "Recommended",
    "关闭": "Close",
    "忽略推荐配置": "Ignore Recommended Configuration",
    "点击\"忽略\"后,不再提示！": "No more prompts after clicking 'Ignore'!",
    "可从开发者文档中获取推荐配置说明": "You can get recommended configuration instructions from the developer documentation",
    "忽略": "Ignore",
    "取消": "Cancel",
    "获取当前时间，使用UTC时间": "Get current time, using UTC",
    "1970年1月1日": "January 1st, 1970",
    "计算时间间隔": "Calculate time interval",
    "获取时间戳（以秒为单位）": "Get timestamp (in seconds)",
    "引擎不依据距离计算衰减": "Engine does not calculate attenuation based on distance",
    "与None完全一致": "Same as None",
    "引擎 InverseSquare Law 计算距离衰减": "Engine calculates distance attenuation using InverseSquare Law",
    "依据外部传入的 Callback 计算距离衰减": "Calculate distance attenuation based on external Callback",
    "左手规则": "Left-hand rule",
    "选择安全边界模式": "Select Safety Boundary Mode",
    "适用于坐着或站在原地进行的体验": "Suitable for sitting or standing experiences",
    "适用于动作较大或需要四处走动的体验": "Suitable for experiences requiring movement",
    "创建虚拟地面": "Create Virtual Floor",
    "系统正在为你自动创建地面": "System is automatically creating the floor for you",
    "创建安全边界": "Create Safety Boundary",
}

def get_ownership(path):
    path = path.replace("\\", "/")
    path_lower = path.lower()
    
    # PICO / ByteDance Internal
    if "pico" in path_lower or "pxr" in path_lower:
        return "Second Party (PICO)"
    if "volcengine" in path_lower:
        return "Second Party (VolcEngine)"
    if "enterprise" in path_lower:
        return "Second Party (PICO Enterprise)"
    if "bytedance" in path_lower:
        return "Second Party (ByteDance)"
    if "tob" in path_lower and "api" in path_lower: # tob_api
        return "Second Party (ToB Platform)"
    
    # Third Party
    if "com.unity" in path_lower:
        return "Third Party (Unity)"
    if "dotween" in path_lower:
        return "Third Party (DOTween)"
    if "tuberenderer" in path_lower:
        return "Third Party (TubeRenderer)"
    if "jeffijoe" in path_lower:
        return "Third Party (Jeffijoe)"
    if "microsoft" in path_lower:
        return "Third Party (Microsoft)"
    if "third party" in path_lower:
        return "Third Party"
    
    # Plugins generic
    if "plugins" in path_lower:
        # If not caught by above (Pico/Volc), assume 3rd party
        return "Third Party (Plugin)"
        
    # First Party / Self
    if "tob xr tools" in path_lower:
        return "First Party (Self-developed)" 
    if "assets/resources" in path_lower or "assets/art" in path_lower or "assets/space scanning" in path_lower:
        return "First Party (Self-developed)"
    if "projectsettings" in path_lower or "packages/manifest" in path_lower:
        return "Config File"
        
    return "Unknown"

def get_treatment(item_type, ownership, path):
    if item_type == "chinese":
        return "Translate to English"
    if item_type == "domain":
        return "Replace with Global Domain / Remove"
    
    # Binary
    if "Second Party" in ownership:
        return "Push for TTP Version / Upgrade"
    if "Third Party" in ownership:
        return "Exempt (Prove Source) / Modify Source"
    if "First Party" in ownership:
        return "Modify Source / Delete"
    
    return "Review"

def find_translations(file_content):
    # This is a mock function since we are not scanning all files in real-time again.
    # We use the hardcoded dictionary.
    translations = []
    for zh, en in TRANSLATIONS.items():
        if zh in file_content:
            translations.append(f"'{zh}' -> '{en}'")
    return "; ".join(translations)

def process_file():
    with open(INPUT_FILE, 'r') as f:
        lines = f.readlines()

    sections = {
        "chinese": [],
        "domain": [],
        "binary_check": []
    }
    
    current_section = None
    
    # Parse the markdown table
    for line in lines:
        line = line.strip()
        if "## Type: chinese" in line:
            current_section = "chinese"
            continue
        elif "## Type: domain" in line:
            current_section = "domain"
            continue
        elif "## Type: binary_check" in line:
            current_section = "binary_check"
            continue
        
        if line.startswith("|") and "---" not in line and "ID" not in line:
            parts = [p.strip() for p in line.split("|")]
            if len(parts) > 3:
                # Format: | ID | Rule | File Path | Handler | Status | Details |
                item = {
                    "id": parts[1],
                    "rule": parts[2],
                    "path": parts[3],
                    "handler": parts[4] if len(parts) > 4 else "",
                    "status": parts[5] if len(parts) > 5 else "",
                    "details": parts[6] if len(parts) > 6 else ""
                }
                if current_section:
                    sections[current_section].append(item)

    # Generate Report Content
    report_lines = []
    report_lines.append("# TTP Compliance Report (Unity)")
    report_lines.append("")
    
    # 1. Aegis (God Shield)
    report_lines.append("## 1. 神盾 (Aegis)")
    
    # 1.1 Code Class
    report_lines.append("### 1.1 代码类 (Code Class)")
    report_lines.append("| ID | Type | File Path | Ownership | Treatment Plan | Translations/Details |")
    report_lines.append("|---|---|---|---|---|---|")
    
    # Merge Chinese and Domain
    code_items = []
    for item in sections["chinese"]:
        item["type"] = "Chinese"
        code_items.append(item)
    for item in sections["domain"]:
        item["type"] = "Domain"
        code_items.append(item)
        
    for item in code_items:
        ownership = get_ownership(item["path"])
        treatment = get_treatment(item["type"].lower(), ownership, item["path"])
        
        details = item["details"]
        if item["type"] == "Chinese":
            # Try to find translation from our dict
            # In a real run, we would read the file. Here we match by filename/content logic or just lookup.
            # We'll do a simple lookup based on what we found earlier.
            found_trans = []
            # Map path to known file content content (conceptually)
            # Since we can't easily map the exact truncated path to the file content we read without fuzzy match,
            # we will use a generic "See dictionary" or specific knowns.
            
            # Specific mapping for the files we analyzed
            if "LocalizationTestEditor.cs" in item["path"]:
                found_trans.append("多语言测试器 -> Localization Tester")
            elif "LocalizationTileTest.cs" in item["path"]:
                found_trans.append("平铺展示 -> Tile Display")
            elif "PXR_Hand.shader" in item["path"]:
                found_trans.append("内部颜色 -> Inner Color")
            elif "TriangleFadeOut" in item["path"]:
                found_trans.append("控制颜色 -> Controls color")
            elif "PUIUtils.cs" in item["path"]:
                found_trans.append("获取当前时间 -> Get current time")
            elif "Localization-zh.csv" in item["path"]:
                found_trans.append("Localization strings (Translate content)")
            elif "Localization.csv" in item["path"]:
                found_trans.append("Localization strings")
            elif "PXR_SDKSettingEditor.cs" in item["path"]:
                found_trans.append("推荐设置 -> Recommended Settings")
            
            if found_trans:
                details = "; ".join(found_trans)
            else:
                details = "Pending Translation"

        report_lines.append(f"| {item['id']} | {item['type']} | {item['path']} | {ownership} | {treatment} | {details} |")

    report_lines.append("")
    
    # 1.2 Binary
    report_lines.append("### 1.2 二进制 (Binary)")
    report_lines.append("| ID | File Type | File Path | Ownership | Treatment Plan |")
    report_lines.append("|---|---|---|---|---|")
    
    for item in sections["binary_check"]:
        ownership = get_ownership(item["path"])
        treatment = get_treatment("binary_check", ownership, item["path"])
        report_lines.append(f"| {item['id']} | {item['rule']} | {item['path']} | {ownership} | {treatment} |")

    report_lines.append("")
    
    # 2. External Dependencies
    report_lines.append("## 2. 外部依赖 (External Dependencies)")
    report_lines.append("| Component/Library | Ownership | Count | Treatment Summary |")
    report_lines.append("|---|---|---|---|")
    
    # Aggregate dependencies
    dependencies = {}
    
    all_items = sections["chinese"] + sections["domain"] + sections["binary_check"]
    for item in all_items:
        ownership = get_ownership(item["path"])
        if ownership == "Unknown" or ownership.startswith("First Party"):
            continue
            
        # Extract component name
        comp_name = "Unknown"
        if "DOTween" in item["path"]:
            comp_name = "DOTween"
        elif "PICO" in item["path"] or "pxr" in item["path"].lower():
            comp_name = "PICO Integration SDK"
        elif "TubeRenderer" in item["path"]:
            comp_name = "TubeRenderer"
        elif "Jeffijoe" in item["path"]:
            comp_name = "Jeffijoe.MessageFormat"
        elif "Microsoft" in item["path"]:
            comp_name = "Microsoft Extensions"
        elif "com.unity" in item["path"]:
            comp_name = "Unity Packages"
        else:
            comp_name = "Other External"
            
        if comp_name not in dependencies:
            dependencies[comp_name] = {"ownership": ownership, "count": 0, "treatment": get_treatment("binary_check", ownership, item["path"])}
        dependencies[comp_name]["count"] += 1

    for name, data in dependencies.items():
        report_lines.append(f"| {name} | {data['ownership']} | {data['count']} | {data['treatment']} |")
        
    # Write to file
    with open(OUTPUT_FILE, 'w') as f:
        f.write("\n".join(report_lines))
        
    print(f"Report generated at {OUTPUT_FILE}")

if __name__ == "__main__":
    process_file()
