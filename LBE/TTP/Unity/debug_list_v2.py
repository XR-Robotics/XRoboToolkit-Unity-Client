import os

file_path = '/Users/bytedance/VO/QY/LBE/TTP/Android/List'
print(f"Checking {file_path}, exists={os.path.exists(file_path)}")

with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
    lines = f.readlines()
    print(f"Total lines: {len(lines)}")
    for i, line in enumerate(lines[:5]):
        parts = line.strip().split('\t')
        print(f"Line {i}: First='{parts[0]}', Len={len(parts)}")
        if len(parts) > 0:
            print(f"  IsDigit: {parts[0].isdigit()}")
