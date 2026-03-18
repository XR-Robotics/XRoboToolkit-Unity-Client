
import os

input_file = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List.md'
output_file = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List_mindmap_final.md'

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
            if len(parts) > 3:
                # parts[1]=ID, parts[2]=Rule, parts[3]=Path
                path = parts[3].replace('`', '').replace('...', '')
                filename = os.path.basename(path) if '/' in path else path
                rule = parts[2]
                
                entry = {
                    'id': parts[1],
                    'rule': rule,
                    'filename': filename
                }
                data[current_type].append(entry)
    return data

def generate_mermaid_mindmap(data):
    lines = ["```mermaid", "mindmap"]
    lines.append("  root((TTP合规治理))")
    
    # 1. Chinese
    if 'chinese' in data:
        lines.append("    Chinese(中文合规)")
        groups = {}
        for item in data['chinese']:
            fname = item['filename']
            ext = os.path.splitext(fname)[1]
            if not ext: ext = "其他"
            if ext not in groups: groups[ext] = []
            groups[ext].append(fname)
            
        for ext, files in groups.items():
            lines.append(f"      {ext}")
            for f in files:
                # Truncate long filenames for better visual
                display_name = f
                if len(f) > 25:
                    display_name = f[:12] + "..." + f[-8:]
                lines.append(f"        {display_name}")

    # 2. Domain
    if 'domain' in data:
        lines.append("    Domain(域名合规)")
        groups = {}
        for item in data['domain']:
            domain = item['rule']
            # Clean domain
            simple_domain = domain.replace('https://', '').replace('http://', '').strip('/')
            if '/' in simple_domain:
                simple_domain = simple_domain.split('/')[0]
            
            if simple_domain not in groups: groups[simple_domain] = []
            groups[simple_domain].append(item['filename'])
            
        for domain, files in groups.items():
            lines.append(f"      {domain}")
            # Deduplicate files in display if same file has multiple hits?
            # Or just list them.
            for f in files:
                display_name = f
                if len(f) > 25:
                    display_name = f[:12] + "..." + f[-8:]
                lines.append(f"        {display_name}")

    # 3. Binary
    if 'binary_check' in data:
        lines.append("    Binary(二进制文件)")
        groups = {}
        for item in data['binary_check']:
            ext = item['rule']
            fname = item['filename']
            if ext not in groups: groups[ext] = []
            groups[ext].append(fname)
            
        for ext, files in groups.items():
            lines.append(f"      {ext}")
            # Special handling for DOTween to reduce noise
            dotween_count = 0
            others = []
            for f in files:
                if 'DOTween' in f:
                    dotween_count += 1
                else:
                    others.append(f)
            
            if dotween_count > 0:
                lines.append(f"        DOTween相关DLL (x{dotween_count})")
            
            # Deduplicate others
            from collections import Counter
            counts = Counter(others)
            for f, count in counts.items():
                display_name = f
                if count > 1:
                    display_name += f" (x{count})"
                lines.append(f"        {display_name}")

    lines.append("```")
    return "\n".join(lines)

def main():
    if not os.path.exists(input_file):
        print(f"Error: {input_file} not found")
        return

    data = parse_markdown_table(input_file)
    content = generate_mermaid_mindmap(data)
    
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write("# TTP Compliance Mindmap Final\n\n")
        f.write(content)
    
    print(content)

if __name__ == "__main__":
    main()
