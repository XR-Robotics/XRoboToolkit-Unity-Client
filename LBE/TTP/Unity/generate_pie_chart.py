import os
from collections import Counter

UNITY_LIST = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List'
ANDROID_LIST = '/Users/bytedance/VO/QY/LBE/TTP/Android/List'

def count_issues(file_path):
    counter = Counter()
    try:
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            lines = f.readlines()
            # Skip header if present
            if lines and "工单ID" in lines[0]:
                lines = lines[1:]
            
            for line in lines:
                parts = line.strip().split('\t')
                if len(parts) >= 5:
                    item_type = parts[4]
                    # Normalize type names if needed
                    counter[item_type] += 1
    except Exception as e:
        print(f"Error reading {file_path}: {e}")
    return counter

unity_counts = count_issues(UNITY_LIST)
android_counts = count_issues(ANDROID_LIST)

total_counts = unity_counts + android_counts

print("Total Distribution:")
for k, v in total_counts.items():
    print(f"{k}: {v}")

print("\nMermaid Pie Chart:")
print("```mermaid")
print("pie title TTP Compliance Issue Distribution")
for k, v in total_counts.items():
    print(f'    "{k}" : {v}')
print("```")
