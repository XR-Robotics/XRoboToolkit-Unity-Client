import os
from collections import Counter

ANDROID_LIST = '/Users/bytedance/VO/QY/LBE/TTP/Android/List'

def generate_android_charts():
    # 1. Count issues
    counts = Counter()
    total_items = 0
    
    try:
        with open(ANDROID_LIST, 'r', encoding='utf-8', errors='ignore') as f:
            lines = f.readlines()
            if lines and "工单ID" in lines[0]:
                lines = lines[1:]
            
            for line in lines:
                parts = line.strip().split('\t')
                if len(parts) >= 5:
                    item_type = parts[4]
                    counts[item_type] += 1
                    total_items += 1
    except Exception as e:
        print(f"Error reading {ANDROID_LIST}: {e}")
        return

    # 2. Generate Markdown Content
    md_lines = []
    md_lines.append("# Android TTP Compliance Overview")
    md_lines.append("")
    
    # Pie Chart
    md_lines.append("## Issue Distribution (Pie Chart)")
    md_lines.append("```mermaid")
    md_lines.append(f"pie title Android Issue Distribution (Total: {total_items})")
    for k, v in counts.items():
        percentage = int((v / total_items) * 100)
        label_map = {
            "binary_check": "Binary Check",
            "chinese": "Chinese Content",
            "domain": "Domain Issue"
        }
        label = label_map.get(k, k)
        md_lines.append(f'    "{label} ({v}, {percentage}%)" : {v}')
    md_lines.append("```")
    md_lines.append("")
    
    # Mindmap
    md_lines.append("## Detailed Classification (Mindmap)")
    md_lines.append("```mermaid")
    md_lines.append("mindmap")
    md_lines.append("  root((Android TTP Issues))")
    
    # Group items for mindmap
    items_by_type = {}
    with open(ANDROID_LIST, 'r', encoding='utf-8', errors='ignore') as f:
        lines = f.readlines()
        if lines and "工单ID" in lines[0]: lines = lines[1:]
        
        for line in lines:
            parts = line.strip().split('\t')
            if len(parts) >= 11:
                item_type = parts[4]
                path = parts[10]
                rule = parts[5]
                
                if item_type not in items_by_type:
                    items_by_type[item_type] = []
                
                # Simplify path for display
                short_path = os.path.basename(path)
                if len(short_path) > 30:
                    short_path = short_path[:27] + "..."
                    
                items_by_type[item_type].append(f"{rule}: {short_path}")

    # Binary Check Branch
    if "binary_check" in items_by_type:
        md_lines.append("    Binary Check")
        # Sub-group by extension
        ext_groups = {}
        for item in items_by_type["binary_check"]:
            rule = item.split(':')[0].strip()
            if rule not in ext_groups: ext_groups[rule] = []
            ext_groups[rule].append(item.split(':')[1].strip())
            
        for ext, files in ext_groups.items():
            md_lines.append(f"      {ext}")
            for f in files:
                # Escape parentheses for mermaid
                f_safe = f.replace("(", "").replace(")", "")
                md_lines.append(f"        {f_safe}")
                
    # Chinese Branch
    if "chinese" in items_by_type:
        md_lines.append("    Chinese Content")
        for item in items_by_type["chinese"]:
             # Extract filename
            parts = item.split(':')
            if len(parts) > 1:
                fname = parts[1].strip()
                md_lines.append(f"      {fname}")

    # Domain Branch
    if "domain" in items_by_type:
        md_lines.append("    Domain Issues")
        for item in items_by_type["domain"]:
             # Extract domain and file
            parts = item.split(':')
            if len(parts) > 1:
                domain = parts[0].replace("https://", "").strip()
                fname = parts[1].strip()
                md_lines.append(f"      {domain} in {fname}")
                
    md_lines.append("```")
    
    output_path = '/Users/bytedance/VO/QY/LBE/TTP/Android/Android_Issue_Charts.md'
    with open(output_path, 'w', encoding='utf-8') as f:
        f.write("\n".join(md_lines))
    print(f"Generated {output_path}")

if __name__ == "__main__":
    generate_android_charts()
