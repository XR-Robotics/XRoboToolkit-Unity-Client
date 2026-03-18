import re

# Source file paths
ORIGINAL_LIST_FILE = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List'
REPORT_FILE = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List_Report.md'
LIST_MD_FILE = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List.md'

def load_original_paths():
    """Load ID to full path mapping from the original List file"""
    id_to_path = {}
    try:
        with open(ORIGINAL_LIST_FILE, 'r') as f:
            for line in f:
                parts = line.strip().split('\t')
                # Check for valid ID (starts with 856...)
                if len(parts) > 10 and parts[0].startswith("856"):
                    item_id = parts[0].strip()
                    # Path is at index 10 based on Read output analysis
                    path = parts[10].strip()
                    id_to_path[item_id] = path
    except Exception as e:
        print(f"Error reading original list: {e}")
    return id_to_path

def update_file(file_path, id_to_path):
    """Update paths in the target file using the mapping"""
    try:
        with open(file_path, 'r') as f:
            lines = f.readlines()
        
        new_lines = []
        updated_count = 0
        
        for line in lines:
            line = line.strip()
            if not line.startswith('|') or '---' in line or 'ID' in line:
                new_lines.append(line + '\n')
                continue

            parts = [p.strip() for p in line.split('|')]
            if len(parts) < 3:
                new_lines.append(line + '\n')
                continue
                
            item_id = parts[1] # ID is always at index 1 in MD table (| ID | ...)
            
            if item_id in id_to_path:
                full_path = id_to_path[item_id]
                
                # Identify path column index based on file structure
                path_idx = -1
                if "List_Report.md" in file_path:
                    # Code: | ID | Status | Type | Path | ... (Path at 4)
                    # Binary: | ID | Status | Type | Path | ... (Path at 4)
                    if len(parts) >= 5: path_idx = 4
                elif "List.md" in file_path:
                    # | ID | Rule | Path | ... (Path at 3)
                    if len(parts) >= 4: path_idx = 3
                
                if path_idx != -1:
                    parts[path_idx] = f"`{full_path}`"
                    updated_count += 1
            
            # Reconstruct line
            new_line = " | ".join(parts) + "\n"
            new_lines.append(new_line)
            
        with open(file_path, 'w') as f:
            f.writelines(new_lines)
            
        print(f"Updated {updated_count} paths in {file_path}")
        
    except Exception as e:
        print(f"Error updating {file_path}: {e}")

def update_feishu_file(file_path, id_to_path):
    """Update paths in the Feishu report file using the mapping"""
    try:
        with open(file_path, 'r') as f:
            lines = f.readlines()
        
        new_lines = []
        updated_count = 0
        current_id = None
        
        for line in lines:
            # Check for ID line: "- ✅ **85668061** (Completed)"
            id_match = re.search(r'\*\*(\d{8})\*\*', line)
            if id_match:
                current_id = id_match.group(1)
                new_lines.append(line)
                continue

            # Fix Path line using ID mapping
            if current_id and current_id in id_to_path:
                if line.strip().startswith("- Path:"):
                     # Preserve indentation
                     indent = line[:line.find("-")]
                     new_lines.append(f"{indent}- Path: `{id_to_path[current_id]}`\n")
                     updated_count += 1
                     continue
            
            new_lines.append(line)
            
        with open(file_path, 'w') as f:
            f.writelines(new_lines)
        print(f"Updated {updated_count} paths in {file_path}")

    except Exception as e:
        print(f"Error updating {file_path}: {e}")

def main():
    id_to_path = load_original_paths()
    print(f"Loaded {len(id_to_path)} paths from original list.")
    
    # update_file(REPORT_FILE, id_to_path) # Already done
    # update_file(LIST_MD_FILE, id_to_path) # Already done
    
    # New task
    FEISHU_FILE = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List_Report_Feishu.md'
    update_feishu_file(FEISHU_FILE, id_to_path)

if __name__ == "__main__":
    main()
