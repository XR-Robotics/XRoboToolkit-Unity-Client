
import re
import os

input_file = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List.md'
output_file = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List_mermaid.md'

def parse_markdown_table(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    data = {}
    current_type = None
    
    for line in lines:
        line = line.strip()
        if line.startswith('## Type:'):
            current_type = line.split(':')[1].strip()
            data[current_type] = []
        elif line.startswith('|') and '---' not in line and 'File Path' not in line:
            parts = [p.strip() for p in line.split('|')]
            # parts[0] is empty string because line starts with |
            # parts[1] is ID, parts[2] is Rule, parts[3] is File Path
            if len(parts) > 3:
                # remove code reference formatting `...` if present for cleaner chart
                path = parts[3].replace('`', '')
                # simplify path for display
                if '/' in path:
                    filename = path.split('/')[-1]
                else:
                    filename = path
                
                entry = {
                    'id': parts[1],
                    'rule': parts[2],
                    'path': path,
                    'filename': filename
                }
                data[current_type].append(entry)
    return data

def generate_mermaid(data):
    # 1. Pie Chart
    pie_chart = "```mermaid\npie\n    title TTP Issues Distribution\n"
    for category, items in data.items():
        pie_chart += f'    "{category}" : {len(items)}\n'
    pie_chart += "```\n\n"

    # 2. Mindmap
    mindmap = "```mermaid\nmindmap\n  root((TTP Compliance))\n"
    for category, items in data.items():
        mindmap += f"    {category}\n"
        # Group by Rule to avoid too many nodes
        grouped_by_rule = {}
        for item in items:
            rule = item['rule']
            if rule not in grouped_by_rule:
                grouped_by_rule[rule] = []
            grouped_by_rule[rule].append(item)
        
        for rule, entries in grouped_by_rule.items():
            # Sanitize rule for mermaid
            safe_rule = rule.replace('"', '').replace('(', '').replace(')', '')
            if len(safe_rule) > 20:
                safe_rule = safe_rule[:20] + "..."
            
            mindmap += f"      {safe_rule}\n"
            for entry in entries:
                # Use filename as leaf node
                filename = entry['filename']
                if len(filename) > 30:
                    filename = filename[:27] + "..."
                mindmap += f"        {filename}\n"
    mindmap += "```\n"

    return pie_chart + mindmap

def main():
    if not os.path.exists(input_file):
        print(f"Error: {input_file} not found")
        return

    data = parse_markdown_table(input_file)
    content = generate_mermaid(data)
    
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write("# TTP Compliance Visualizations\n\n")
        f.write(content)
    
    print(content)

if __name__ == "__main__":
    main()
