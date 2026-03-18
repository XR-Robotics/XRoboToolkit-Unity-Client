file_path = '/Users/bytedance/VO/QY/LBE/TTP/Android/List'

with open(file_path, 'r') as f:
    for i in range(5):
        line = f.readline()
        if not line: break
        parts = line.strip().split('\t')
        print(f"Line {i}: Len={len(parts)}")
        for idx, part in enumerate(parts):
            print(f"  [{idx}] {part}")
