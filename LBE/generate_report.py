
import os
import re

input_file = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List.md'
output_file = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List_Report.md'

# Translation dictionary
translations = {
    "中文": "Chinese",
    "提示": "Tip",
    "场景中已存在一个多语言测试器": "A localization tester already exists in the scene",
    "好的": "OK",
    "多语言测试/平铺展示当前选中的UI": "Multilingual Test/Tile display currently selected UI",
    "引擎 InverseSquare Law 计算距离衰减": "Engine InverseSquare Law calculates distance attenuation",
    "依据外部传入的 Callback 计算距离衰减": "Calculates distance attenuation based on externally passed Callback",
    "左手规则": "Left-hand rule",
    "domain": "Domain"
}

def translate_text(text):
    for key, value in translations.items():
        text = text.replace(key, value)
    return text

def determine_ownership(path):
    path_lower = path.lower()
    if 'dotween' in path_lower:
        return 'Third-party (Open Source/Commercial)'
    if 'jeffijoe' in path_lower or 'microsoft' in path_lower or 'newtonsoft' in path_lower:
        return 'Third-party (Open Source)'
    if 'openh264' in path_lower:
        return 'Third-party (Open Source)'
    
    # Second-party: Company internal but not team
    if 'pico unity integration sdk' in path_lower:
        return 'Second-party (PICO SDK)'
    if 'volcengine' in path_lower or 'rtc' in path_lower:
        return 'Second-party (VolcEngine)'
    if 'pxr' in path_lower or 'pico' in path_lower: # Likely PICO libraries
        return 'Second-party (PICO)'
    if 'bytedance' in path_lower or 'blspace' in path_lower:
        return 'Second-party (ByteDance)'
    
    # Self-developed: Usually in Assets root or specific feature folders
    if path.startswith('Assets/'):
        if 'third party' in path_lower or 'plugins' in path_lower:
             # Already caught above if matched, but if not:
             return 'Third-party (Unclassified) or Second-party'
        return 'Self-developed'
    
    return 'Unknown'

def determine_treatment(ownership, file_type):
    if 'Self-developed' in ownership:
        return 'Self-fix (Modify Code)'
    if 'Second-party' in ownership:
        return 'Push for TTP Version / Upgrade'
    if 'Third-party' in ownership:
        return 'Exemption (Source Proof Needed) or Source Integration'
    return 'Investigation Needed'

def parse_and_transform(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    processed_sections = {
        'chinese': [],
        'domain': [],
        'binary_check': []
    }
    
    current_type = None
    
    for line in lines:
        line = line.strip()
        if line.startswith('## Type:'):
            current_type = line.split(':')[1].strip()
        elif line.startswith('|') and '---' not in line and 'File Path' not in line:
            parts = [p.strip() for p in line.split('|')]
            if len(parts) > 3:
                # Original columns: 
                # | ID | Rule | File Path | Handler | Status | Details |
                # parts[0]='', parts[1]=ID, parts[2]=Rule, parts[3]=Path, parts[4]=Handler, parts[5]=Status, parts[6]=Details
                
                entry = {
                    'id': parts[1],
                    'rule': parts[2],
                    'path': parts[3].replace('`', ''),
                    'handler': parts[4],
                    'status': parts[5],
                    'details': parts[6] if len(parts) > 6 else ""
                }
                
                if current_type == 'chinese':
                    entry['details'] = translate_text(entry['details'])
                    entry['rule'] = translate_text(entry['rule'])
                    processed_sections['chinese'].append(entry)
                    
                elif current_type == 'domain':
                    processed_sections['domain'].append(entry)
                    
                elif current_type == 'binary_check':
                    ownership = determine_ownership(entry['path'])
                    treatment = determine_treatment(ownership, entry['rule'])
                    entry['ownership'] = ownership
                    entry['treatment'] = treatment
                    processed_sections['binary_check'].append(entry)
                    
    return processed_sections

def generate_report(sections):
    lines = []
    lines.append("# TTP Compliance Report")
    lines.append("")
    
    # 1. Aegis
    lines.append("## 1. 神盾 (Aegis Scan Results)")
    
    # 1.1 Code
    lines.append("### 1.1 代码类 (Code Issues - Chinese/Sensitive Words)")
    lines.append("| ID | Rule | File Path | Handler | Status | Details |")
    lines.append("|--- |--- |--- |--- |--- |--- |")
    for item in sections['chinese']:
        lines.append(f"| {item['id']} | {item['rule']} | `{item['path']}` | {item['handler']} | {item['status']} | {item['details']} |")
    lines.append("")
    
    # 1.2 Binary
    lines.append("### 1.2 二进制 (Binary Check)")
    lines.append("| ID | Rule | File Path | Dependency Ownership | Treatment Plan | Handler | Status |")
    lines.append("|--- |--- |--- |--- |--- |--- |--- |")
    for item in sections['binary_check']:
        lines.append(f"| {item['id']} | {item['rule']} | `{item['path']}` | {item['ownership']} | {item['treatment']} | {item['handler']} | {item['status']} |")
    lines.append("")
    
    # 2. External Dependencies
    lines.append("## 2. 外部依赖 (External Dependencies)")
    
    # 2.1 Domains
    lines.append("### 2.1 域名 (Domains)")
    lines.append("| ID | Rule | File Path | Handler | Status | Details |")
    lines.append("|--- |--- |--- |--- |--- |--- |")
    for item in sections['domain']:
        lines.append(f"| {item['id']} | {item['rule']} | `{item['path']}` | {item['handler']} | {item['status']} | {item['details']} |")
    lines.append("")
    
    # 2.2 Inventory Summary
    lines.append("### 2.2 依赖盘点 (Dependency Inventory)")
    
    # Collect unique dependencies
    dependencies = {}
    for item in sections['binary_check']:
        owner = item['ownership']
        if owner not in dependencies:
            dependencies[owner] = set()
        
        # Try to extract lib name
        filename = os.path.basename(item['path'])
        # Simple heuristic
        if 'DOTween' in filename:
            lib_name = 'DOTween'
        elif 'Pico' in filename or 'pxr' in filename:
            lib_name = 'PICO SDK Components'
        else:
            lib_name = filename
            
        dependencies[owner].add(lib_name)
        
    for owner, libs in dependencies.items():
        lines.append(f"- **{owner}**")
        for lib in sorted(list(libs)):
            lines.append(f"  - {lib}")
    
    return "\n".join(lines)

def main():
    if not os.path.exists(input_file):
        print(f"Error: {input_file} not found")
        return

    sections = parse_and_transform(input_file)
    content = generate_report(sections)
    
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write(content)
    
    print(f"Report generated at {output_file}")

if __name__ == "__main__":
    main()
