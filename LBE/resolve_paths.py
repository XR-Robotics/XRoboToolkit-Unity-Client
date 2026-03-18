import os
import re
import json

def parse_markdown(file_path):
    files_to_find = []
    with open(file_path, 'r') as f:
        lines = f.readlines()
    
    # Regex to capture the content between pipes
    # Example: | 85668061 | 中文 | `...s/Framework/UI/Editor/LocalizationTestEditor.cs` | lijialun.qwq | open |  |
    # We want the 3rd column (index 2)
    
    for line in lines:
        if not line.strip().startswith('|'):
            continue
        if 'File Path' in line or '---' in line:
            continue
            
        parts = [p.strip() for p in line.split('|')]
        if len(parts) > 3:
            raw_path = parts[3].strip('` ') # Index 3 because split gives empty string at start if line starts with |
            if raw_path:
                filename = os.path.basename(raw_path)
                # Remove ... prefix if present for matching suffix
                clean_path = raw_path.replace('...', '')
                files_to_find.append({'raw': raw_path, 'clean': clean_path, 'filename': filename})
    
    return files_to_find

def find_files(root_dir, target_filenames):
    found_files = {} # filename -> list of full paths
    target_set = set(target_filenames)
    
    for root, dirs, files in os.walk(root_dir):
        for file in files:
            if file in target_set:
                if file not in found_files:
                    found_files[file] = []
                found_files[file].append(os.path.join(root, file))
                
    return found_files

def resolve_paths(files_to_find, found_files):
    result = {}
    
    for item in files_to_find:
        filename = item['filename']
        raw_path = item['raw']
        clean_path = item['clean']
        
        candidates = found_files.get(filename, [])
        
        if not candidates:
            # result[raw_path] = None
            continue # Skip if not found, or maybe set to None? User asked for mapping.
            
        if len(candidates) == 1:
            result[filename] = candidates[0]
        else:
            # Try to match suffix
            best_match = None
            for cand in candidates:
                if cand.endswith(clean_path):
                    best_match = cand
                    break
            
            if best_match:
                result[filename] = best_match
            else:
                # If no suffix match, just take the first one or leave ambiguous? 
                # Let's take the first one but maybe log a warning? 
                # For the purpose of this task, let's pick the first one.
                result[filename] = candidates[0]
                
    return result

def main():
    list_md_path = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List.md'
    search_root = '/Users/bytedance/VO/QY/LBE'
    
    files_to_find = parse_markdown(list_md_path)
    target_filenames = [f['filename'] for f in files_to_find]
    
    found_files = find_files(search_root, target_filenames)
    
    mapping = resolve_paths(files_to_find, found_files)
    
    print(json.dumps(mapping, indent=4))

if __name__ == '__main__':
    main()
