
import csv
import os

input_file = '/Users/bytedance/VO/QY/LBE/TTP/List'
output_file = '/Users/bytedance/VO/QY/LBE/TTP/List.md'

def main():
    with open(input_file, 'r', encoding='utf-8') as f:
        # It seems to be tab-separated
        reader = csv.reader(f, delimiter='\t')
        headers = next(reader)
        rows = list(reader)

    # Group by Scan Type (index 4)
    grouped = {}
    for row in rows:
        scan_type = row[4]
        if scan_type not in grouped:
            grouped[scan_type] = []
        grouped[scan_type].append(row)

    with open(output_file, 'w', encoding='utf-8') as f:
        f.write("# TTP Compliance Issues List\n\n")
        
        for scan_type, items in grouped.items():
            f.write(f"## Type: {scan_type}\n\n")
            
            # Select relevant columns for readability
            # 0: ID, 5: Rule, 10: Path, 6: Handler, 12: Link, 14: Code
            # Let's try to keep most columns but make it a table
            
            f.write("| ID | Rule | File Path | Handler | Status | Details |\n")
            f.write("|--- |--- |--- |--- |--- |--- |\n")
            
            for row in items:
                # Handle potential missing columns
                while len(row) < 15:
                    row.append("")
                
                id_ = row[0]
                rule = row[5]
                path = row[10]
                handler = row[6]
                status = row[1]
                
                # detail might be code or domain
                detail = ""
                if scan_type == 'domain':
                     detail = row[5] # The domain is in the "Hit Rule" column actually? 
                     # Wait, looking at the file content:
                     # Row 20: 85668002 ... domain ... https://developer-global.pico-interactive.com ...
                     # Column 5 is "Scan Type" (0-indexed -> 4)
                     # Column 6 is "Hit Rule" (0-indexed -> 5) -> "https://developer-global..."
                elif scan_type == 'chinese':
                    detail = row[14].replace('\n', '<br>') # Code details
                elif scan_type == 'binary_check':
                    detail = row[5] # Extension like .so, .dll
                
                # Clean up path (basename or shorten if too long)
                short_path = path
                if len(short_path) > 50:
                    short_path = "..." + short_path[-47:]
                
                f.write(f"| {id_} | {rule} | `{short_path}` | {handler} | {status} | {detail} |\n")
            
            f.write("\n")

if __name__ == "__main__":
    main()
