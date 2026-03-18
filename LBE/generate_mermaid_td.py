
import os

input_file = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List.md'
output_file = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List_graph_td.md'

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

def generate_mermaid_td(data):
    # Using 'graph TD' (Top-Down)
    # To make it readable, we might need separate charts or a very structured one
    
    lines = ["```mermaid", "graph TD"]
    lines.append("    root[TTP Compliance Issues]:::rootClass")
    
    # Define styles
    lines.append("    classDef rootClass fill:#f96,stroke:#333,stroke-width:2px,color:white;")
    lines.append("    classDef typeClass fill:#69f,stroke:#333,stroke-width:1px,color:white;")
    lines.append("    classDef groupClass fill:#ff9,stroke:#333,stroke-width:1px;")
    lines.append("    classDef itemClass fill:#fff,stroke:#333,stroke-width:1px;")

    # Process each category
    for category, items in data.items():
        cat_node = f"cat_{category}"
        lines.append(f"    root --> {cat_node}[{category.capitalize()}]:::typeClass")
        
        # Grouping logic to avoid too many nodes
        groups = {}
        
        if category == 'chinese':
            # Group by simple logical grouping or just list them
            # Since there are 14, maybe just link them directly or group by file type?
            for item in items:
                fname = item['filename']
                ext = os.path.splitext(fname)[1]
                if ext not in groups:
                    groups[ext] = []
                groups[ext].append(fname)
                
            for ext, files in groups.items():
                group_node = f"grp_{category}_{ext.replace('.', '')}"
                lines.append(f"    {cat_node} --> {group_node}({ext} files):::groupClass")
                for f in files:
                    safe_f = f.replace('.', '_').replace(' ', '_').replace('-', '_')
                    # truncate if too long
                    display_name = f if len(f) < 20 else f[:17] + "..."
                    lines.append(f"    {group_node} --> {safe_f}[\"{display_name}\"]:::itemClass")

        elif category == 'domain':
            # Group by domain (rule)
            for item in items:
                domain = item['rule']
                # Simplify domain for display
                simple_domain = domain.replace('https://', '').replace('http://', '').split('/')[0]
                if simple_domain not in groups:
                    groups[simple_domain] = []
                groups[simple_domain].append(item['filename'])
            
            i = 0
            for domain, files in groups.items():
                i += 1
                group_node = f"grp_{category}_{i}"
                lines.append(f"    {cat_node} --> {group_node}[\"{domain}\"]:::groupClass")
                for f in files:
                    safe_f = f.replace('.', '_').replace(' ', '_').replace('-', '_') + f"_{i}" # unique id
                    display_name = f if len(f) < 20 else f[:17] + "..."
                    lines.append(f"    {group_node} --> {safe_f}[\"{display_name}\"]:::itemClass")

        elif category == 'binary_check':
            # Group by extension (rule is typically the extension like .so)
            for item in items:
                ext = item['rule']
                if ext not in groups:
                    groups[ext] = []
                groups[ext].append(item['filename'])
            
            for ext, files in groups.items():
                clean_ext = ext.replace('.', '')
                group_node = f"grp_{category}_{clean_ext}"
                lines.append(f"    {cat_node} --> {group_node}({ext}):::groupClass")
                
                # If too many files, maybe just show count? 
                # Or list them. Binary has 38 items.
                # Let's list them but compact
                for f in files:
                    safe_f = f.replace('.', '_').replace(' ', '_').replace('-', '_') + f"_{clean_ext}"
                    display_name = f if len(f) < 25 else f[:22] + "..."
                    lines.append(f"    {group_node} --> {safe_f}[\"{display_name}\"]:::itemClass")

    lines.append("```")
    return "\n".join(lines)

def main():
    if not os.path.exists(input_file):
        print(f"Error: {input_file} not found")
        return

    data = parse_markdown_table(input_file)
    content = generate_mermaid_td(data)
    
    with open(output_file, 'w', encoding='utf-8') as f:
        f.write("# TTP Compliance Graph TD\n\n")
        f.write(content)
    
    print(content)

if __name__ == "__main__":
    main()
