
import os

input_file = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List.md'
output_file = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List_markmap.md'

def parse_markdown_table(file_path):
    if not os.path.exists(file_path):
        return {}
        
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

def generate_markmap(data):
    lines = []
    lines.append("# TTP合规治理")
    
    # 1. Chinese
    if 'chinese' in data:
        lines.append("- Chinese (中文合规)")
        groups = {}
        for item in data['chinese']:
            fname = item['filename']
            ext = os.path.splitext(fname)[1]
            if not ext: ext = "其他"
            if ext not in groups: groups[ext] = []
            groups[ext].append(fname)
            
        for ext, files in groups.items():
            lines.append(f"    - {ext}")
            # Deduplicate
            file_counts = {}
            for f in files:
                file_counts[f] = file_counts.get(f, 0) + 1
                
            for f, count in file_counts.items():
                display = f
                if count > 1:
                    display += f" x{count}"
                lines.append(f"        - {display}")

    # 2. Domain
    if 'domain' in data:
        lines.append("- Domain (域名合规)")
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
            lines.append(f"    - {domain}")
            # Deduplicate
            file_counts = {}
            for f in files:
                file_counts[f] = file_counts.get(f, 0) + 1
            
            for f, count in file_counts.items():
                display = f
                if count > 1:
                    display += f" x{count}"
                lines.append(f"        - {display}")

    # 3. Binary
    if 'binary_check' in data:
        lines.append("- Binary (二进制文件)")
        groups = {}
        for item in data['binary_check']:
            ext = item['rule']
            fname = item['filename']
            if ext not in groups: groups[ext] = []
            groups[ext].append(fname)
            
        for ext, files in groups.items():
            lines.append(f"    - {ext}")
            
            # Special handling for DOTween
            dotween_count = 0
            others = []
            for f in files:
                if 'DOTween' in f:
                    dotween_count += 1
                else:
                    others.append(f)
            
            if dotween_count > 0:
                lines.append(f"        - DOTween相关DLL (共{dotween_count}个)")
            
            # Deduplicate others
            from collections import Counter
            counts = Counter(others)
            for f, count in counts.items():
                display_name = f
                if count > 1:
                    display_name += f" (x{count})"
                lines.append(f"        - {display_name}")

    return "\n".join(lines)

def main():
    data = parse_markdown_table(input_file)
    if not data:
        print(f"Error: No data found in {input_file}")
        return

    content = generate_markmap(data)
    
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write(content)
    
    print(content)

if __name__ == "__main__":
    main()
