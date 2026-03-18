import csv

ORIGINAL_LIST = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List'
OUTPUT_LIST = '/Users/bytedance/VO/QY/LBE/TTP/Unity/List_Updated.tsv'

# List of IDs that have been fixed/completed
COMPLETED_IDS = {
    "85668061", "85668057", "85668052", "85668051", "85668049", 
    "85668035", "85668028", "85668023", "85668011", "85668010", 
    "85668009", "85668005", "85668004", "85668003"
}

def process():
    try:
        with open(ORIGINAL_LIST, 'r', encoding='utf-8', errors='ignore') as f_in:
            lines = f_in.readlines()
            
        new_lines = []
        
        for line in lines:
            parts = line.strip().split('\t')
            
            # Header or empty line
            if len(parts) < 2 or not parts[0].isdigit():
                new_lines.append(line.strip())
                continue
                
            item_id = parts[0]
            
            # Check if this ID is marked as Completed in our list
            if item_id in COMPLETED_IDS:
                # Update Status (Column 1: open -> fixed)
                if len(parts) > 1:
                    parts[1] = "fixed"
                
                # Update Node (Column 11: need fix -> fixed)
                if len(parts) > 11:
                    parts[11] = "fixed"
                    
                # Optionally add a note in Handler (Column 6)
                if len(parts) > 6:
                    if not parts[6]: parts[6] = "Gemini"
            
            new_lines.append("\t".join(parts))
            
        with open(OUTPUT_LIST, 'w', encoding='utf-8') as f_out:
            f_out.write("\n".join(new_lines))
            
        print(f"Generated updated list at {OUTPUT_LIST}")
        print(f"Total rows: {len(new_lines)}")
        
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    process()
