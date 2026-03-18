import re

INPUT_FILE = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List_Report.md'
OUTPUT_FILE = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List_Report.md'
FEISHU_FILE = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List_Report_Feishu.md'

COMPLETED_IDS = [
    "85668061", # LocalizationTestEditor.cs
    "85668057", # LocalizationTileTest.cs
    "85668052", # PXR_Audio_Spatializer_Types.cs
    "85668051", # TubeRenderer.cs
    "85668035", # PXR_Hand.shader
    "85668028", # TriangleFadeOutFromCenter.shader
    "85668011", # PicoGs.cs
    "85668010", # PUIUtils.cs
    "85668009", # PlatformConfig.cs
    "85668005", # PXR_SDKSettingEditor.cs (Chinese)
]

def process_reports():
    with open(INPUT_FILE, 'r') as f:
        lines = f.readlines()

    new_lines = []
    feishu_lines = []
    
    feishu_lines.append("# TTP Compliance Report (Feishu Version)")
    
    current_section = ""
    table_header_processed = False
    
    # Process lines
    for line in lines:
        line = line.strip()
        
        if line.startswith("#"):
            new_lines.append(line)
            feishu_lines.append(line)
            current_section = line
            continue
            
        if line.startswith("|"):
            parts = [p.strip() for p in line.split("|")]
            
            # Skip empty lines or malformed
            if len(parts) < 3:
                new_lines.append(line)
                feishu_lines.append(line)
                continue
            
            # Check for header rows
            if "ID" in parts[1] and "Type" in parts[2]:
                new_lines.append("| ID | Status | Type | File Path | Ownership | Treatment Plan | Translations/Details |")
                new_lines.append("|---|---|---|---|---|---|---|")
                feishu_lines.append(f"**Code Class Issues**")
                continue
            elif "ID" in parts[1] and "File Type" in parts[2]:
                new_lines.append("| ID | Status | File Type | File Path | Ownership | Treatment Plan |")
                new_lines.append("|---|---|---|---|---|---|")
                feishu_lines.append(f"**Binary Issues**")
                continue
            elif "Component/Library" in parts[1]:
                new_lines.append(line)
                feishu_lines.append(f"**External Dependencies**")
                continue
            elif "---" in line:
                # Skip divider lines in Feishu doc, keep in MD table
                continue

            # Data rows
            item_id = parts[1]
            status = "Completed" if item_id in COMPLETED_IDS else "Pending"
            icon = "✅" if status == "Completed" else "⏳"
            
            # Construct new table row
            if len(parts) >= 7: # Code table
                new_row = f"| {parts[1]} | {status} | {parts[2]} | {parts[3]} | {parts[4]} | {parts[5]} | {parts[6]} |"
                new_lines.append(new_row)
                
                # Feishu list item
                feishu_lines.append(f"- {icon} **{parts[1]}** ({status})")
                feishu_lines.append(f"  - Type: {parts[2]}")
                feishu_lines.append(f"  - Path: {parts[3]}")
                feishu_lines.append(f"  - Plan: {parts[5]}")
                if parts[6]: feishu_lines.append(f"  - Details: {parts[6]}")
                
            elif len(parts) >= 6: # Binary table
                new_row = f"| {parts[1]} | {status} | {parts[2]} | {parts[3]} | {parts[4]} | {parts[5]} |"
                new_lines.append(new_row)
                
                feishu_lines.append(f"- {icon} **{parts[1]}** ({status})")
                feishu_lines.append(f"  - Type: {parts[2]}")
                feishu_lines.append(f"  - Path: {parts[3]}")
                feishu_lines.append(f"  - Ownership: {parts[4]}")
                feishu_lines.append(f"  - Plan: {parts[5]}")
                
            elif len(parts) >= 5: # Dependencies table
                new_lines.append(line)
                feishu_lines.append(f"- **{parts[1]}**")
                feishu_lines.append(f"  - Ownership: {parts[2]}")
                feishu_lines.append(f"  - Count: {parts[3]}")
                feishu_lines.append(f"  - Summary: {parts[4]}")
            else:
                new_lines.append(line)

        else:
            new_lines.append(line)
            feishu_lines.append(line)

    # Write files
    with open(OUTPUT_FILE, 'w') as f:
        f.write("\n".join(new_lines))
        
    with open(FEISHU_FILE, 'w') as f:
        f.write("\n".join(feishu_lines))
        
    print(f"Updated report at {OUTPUT_FILE}")
    print(f"Generated Feishu report at {FEISHU_FILE}")

if __name__ == "__main__":
    process_reports()
