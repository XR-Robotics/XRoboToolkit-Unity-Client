import os

# Configuration
UNITY_LIST = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List'
UNITY_OUTPUT = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List_Report_Feishu.md'
UNITY_COMPLETED = {
    "85668061", "85668057", "85668052", "85668051", "85668049", 
    "85668035", "85668028", "85668023", "85668011", "85668010", 
    "85668009", "85668005", "85668004", "85668003", "85667973", "85667966", "85667960", "85667961", "85667963"
}

ANDROID_LIST = '/Users/bytedance/VO/QY/LBE/TTP/Android/List'
ANDROID_OUTPUT = '/Users/bytedance/VO/QY/LBE/TTP/Android/List_Report_Feishu.md'
ANDROID_COMPLETED = {
    "85670788", "85670758", "85670757", "85667849", "85667848", "85667847", "85667840", "85667839", "85667835", "85667824"
}

def get_ownership(path):
    path_lower = path.lower().replace("\\", "/")
    # Second Party
    if any(k in path_lower for k in ["pico", "pxr", "volcengine", "bytedance", "tob_api", "enterprise", "feishu", "lark"]):
        return "Second Party"
    # Third Party
    if any(k in path_lower for k in ["com.unity", "dotween", "tuberenderer", "jeffijoe", "microsoft", "third party", "plugins", "unity-classes", "android", "google", "androidx"]):
        return "Third Party"
    return "First Party"

def generate_report(input_path, output_path, completed_ids):
    try:
        with open(input_path, 'r', encoding='utf-8', errors='ignore') as f:
            lines = f.readlines()
            
        data_by_type = {}
        dependencies = {} # Store dependency items: {comp_name: {"ownership": str, "items": []}}
        type_order = ["chinese", "domain", "binary_check"]
        
        # Skip header
        if lines and "工单ID" in lines[0]:
            lines = lines[1:]

        for line in lines:
            parts = line.strip().split('\t')
            # Basic validation
            if len(parts) < 5: 
                continue

            item_id = parts[0]
            if not item_id.isdigit():
                continue
                
            status = parts[1]
            item_type = parts[4]
            rule = parts[5]
            handler = parts[6] if len(parts) > 6 else ""
            
            # Path is usually at index 10
            path = parts[10] if len(parts) > 10 else ""
            
            # Details (Code Detail) is usually at index 14
            details = parts[14] if len(parts) > 14 else ""
            if not details and len(parts) > 12:
                 # Fallback to link or other info if details missing
                 pass
            
            # Update status
            if item_id in completed_ids:
                status = "fixed"
                if not handler: handler = "Gemini"
            
            # Analyze ownership for binary
            ownership = get_ownership(path)
            
            # If binary check and external dependency
            if item_type == "binary_check" and ownership != "First Party":
                # Strikethrough details and append note
                if details:
                    details = f"~~{details}~~ <br> **外部依赖整体跟进**"
                else:
                    details = "**外部依赖整体跟进**"
                
                # Add to dependency summary
                # Group by rough component name
                comp_name = "Unknown"
                path_lower = path.lower()
                if "pico" in path_lower or "pxr" in path_lower: comp_name = "PICO SDK"
                elif "dotween" in path_lower: comp_name = "DOTween"
                elif "unity" in path_lower: comp_name = "Unity"
                elif "android" in path_lower: comp_name = "Android SDK"
                elif "google" in path_lower: comp_name = "Google Libs"
                elif "jeffijoe" in path_lower: comp_name = "Jeffijoe Libs"
                elif "microsoft" in path_lower: comp_name = "Microsoft Libs"
                else: comp_name = "Other External"
                
                # Correction for pxrnotification.jar if it is misclassified
                if "pxrnotification.jar" in path_lower:
                    comp_name = "PICO SDK"
                
                if comp_name not in dependencies:
                    dependencies[comp_name] = {"ownership": ownership, "items": []}
                
                dependencies[comp_name]["items"].append({
                    "id": item_id,
                    "path": path,
                    "status": status
                })

            if item_type not in data_by_type:
                data_by_type[item_type] = []
            
            data_by_type[item_type].append({
                "id": item_id,
                "rule": rule,
                "path": f"`{path}`",
                "handler": handler,
                "status": status,
                "details": details
            })
                
        # Generate Markdown
        md_lines = ["# TTP Compliance Issues List", ""]
        
        # 1. Main Tables
        sorted_keys = [k for k in type_order if k in data_by_type]
        other_keys = [k for k in data_by_type.keys() if k not in type_order]
        
        for section in sorted_keys + other_keys:
            md_lines.append(f"## Type: {section}")
            md_lines.append("")
            md_lines.append("| ID | Rule | File Path | Handler | Status | Details |")
            md_lines.append("|---|---|---|---|---|---|")
            
            for item in data_by_type[section]:
                details_clean = item['details'].replace("|", "\\|")
                # Ensure no unescaped pipes break the table
                row = f"| {item['id']} | {item['rule']} | {item['path']} | {item['handler']} | {item['status']} | {details_clean} |"
                md_lines.append(row)
            md_lines.append("")
            
        # 2. External Dependencies Summary & Details
        if dependencies:
            md_lines.append("## External Dependencies Summary")
            md_lines.append("")
            
            # Summary Table
            md_lines.append("| Component | Ownership | Binary Count | Note |")
            md_lines.append("|---|---|---|---|")
            for comp, info in dependencies.items():
                count = len(info['items'])
                md_lines.append(f"| {comp} | {info['ownership']} | {count} | Follow up with owner |")
            md_lines.append("")
            
            # Detailed Tables per Component
            md_lines.append("### External Dependencies Details")
            md_lines.append("")
            
            for comp, info in dependencies.items():
                md_lines.append(f"#### {comp} ({len(info['items'])})")
                md_lines.append("| ID | File Path | Status |")
                md_lines.append("|---|---|---|")
                for item in info['items']:
                    md_lines.append(f"| {item['id']} | `{item['path']}` | {item['status']} |")
                md_lines.append("")
            
        with open(output_path, 'w', encoding='utf-8') as f:
            f.write("\n".join(md_lines))
            
        print(f"Generated {output_path}")
        
    except Exception as e:
        print(f"Error processing {input_path}: {e}")
        import traceback
        traceback.print_exc()

if __name__ == "__main__":
    print("Generating Unity Report...")
    generate_report(UNITY_LIST, UNITY_OUTPUT, UNITY_COMPLETED)
    print("Generating Android Report...")
    generate_report(ANDROID_LIST, ANDROID_OUTPUT, ANDROID_COMPLETED)
