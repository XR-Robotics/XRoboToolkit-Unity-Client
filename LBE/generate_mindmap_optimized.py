
import os
import re

input_file = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List.md'
output_file = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List_mindmap_optimized.md'

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
                    'filename': filename,
                    'path': path
                }
                data[current_type].append(entry)
    return data

def generate_mermaid_mindmap(data):
    lines = ["```mermaid", "mindmap"]
    lines.append("  root((TTP合规治理))")
    
    # 1. Chinese (按文件类型分组)
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
            lines.append(f"      {ext}文件")
            # 去重并统计
            file_counts = {}
            for f in files:
                file_counts[f] = file_counts.get(f, 0) + 1
            
            for f, count in file_counts.items():
                display = f
                if count > 1:
                    display += f" x{count}"
                # 截断过长文件名
                if len(display) > 25:
                    display = display[:12] + "..." + display[-10:]
                lines.append(f"        {display}")

    # 2. Domain (按域名分组)
    if 'domain' in data:
        lines.append("    Domain(域名合规)")
        groups = {}
        for item in data['domain']:
            domain = item['rule']
            # 简化域名显示
            simple_domain = domain.replace('https://', '').replace('http://', '')
            if '/' in simple_domain:
                simple_domain = simple_domain.split('/')[0]
            
            # 特殊处理 bytedance.net
            if 'bytedance.net' in simple_domain:
                simple_domain = '内网源(bytedance)'
            
            if simple_domain not in groups: groups[simple_domain] = []
            groups[simple_domain].append(item['filename'])
            
        for domain, files in groups.items():
            lines.append(f"      {domain}")
            file_counts = {}
            for f in files:
                file_counts[f] = file_counts.get(f, 0) + 1
            
            for f, count in file_counts.items():
                display = f
                if count > 1:
                    display += f" x{count}"
                if len(display) > 25:
                     display = display[:12] + "..." + display[-10:]
                lines.append(f"        {display}")

    # 3. Binary (按类型分组，合并同名文件)
    if 'binary_check' in data:
        lines.append("    Binary(二进制文件)")
        groups = {}
        for item in data['binary_check']:
            ext = item['rule'] # .so, .dll
            fname = item['filename']
            if ext not in groups: groups[ext] = []
            groups[ext].append(fname)
            
        for ext, files in groups.items():
            lines.append(f"      {ext}")
            # 强力去重：只看文件名，统计数量
            file_counts = {}
            for f in files:
                # 合并 DOTween 相关的
                if 'DOTween' in f:
                    file_counts['DOTween相关.dll'] = file_counts.get('DOTween相关.dll', 0) + 1
                else:
                    file_counts[f] = file_counts.get(f, 0) + 1
            
            for f, count in file_counts.items():
                display = f
                if count > 1:
                    display += f" (x{count})"
                lines.append(f"        {display}")

    lines.append("```")
    return "\n".join(lines)

def main():
    if not os.path.exists(input_file):
        print(f"Error: {input_file} not found")
        return

    data = parse_markdown_table(input_file)
    content = generate_mermaid_mindmap(data)
    
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write("# TTP Compliance Mindmap Optimized\n\n")
        f.write(content)
    
    print(content)

if __name__ == "__main__":
    main()
