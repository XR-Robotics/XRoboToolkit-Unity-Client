import csv
import re
import io

CSV_PATH = '/Users/bytedance/VO/QY/LBE/LSpaceU3d/Assets/Resources/Localization/Localization.csv'

def clean_csv():
    # Regular expression to match the ICU pattern
    # It looks like: {num, plural, ... other {TEXT}}
    # We want to extract TEXT from "other {TEXT}"
    
    # Pattern explanation:
    # \{num, plural,    : Start of pattern
    # .*?               : Match anything non-greedy until...
    # other\s*\{        : "other" followed by "{"
    # ([^{}]*)          : Capture the content inside (assuming no nested braces for now, or simple text)
    # \}                : Closing brace for "other"
    # .*?               : Match anything after until...
    # \}                : Closing brace for the whole pattern
    
    # However, some languages might have complex nested structures.
    # Let's try a more robust parsing approach.
    
    with open(CSV_PATH, 'r', encoding='utf-8') as f:
        content = f.read()
        
    # Simple regex to find the whole block: "{num, plural, ...}"
    # Because braces can be nested, regex is tricky. 
    # But looking at the file, the structure seems consistently: {num, plural, ... other {TARGET} ...}
    # Note: the "other" block is mandatory in ICU.
    
    def replace_icu(match):
        full_text = match.group(0)
        # Find "other {" inside the match
        other_start = full_text.find("other {")
        if other_start == -1:
            other_start = full_text.find("other{")
            
        if other_start != -1:
            # Find the closing brace for "other"
            brace_count = 0
            start_content = full_text.find("{", other_start) + 1
            
            for i in range(start_content, len(full_text)):
                if full_text[i] == '{':
                    brace_count += 1
                elif full_text[i] == '}':
                    if brace_count == 0:
                        # Found the closing brace for "other"
                        return full_text[start_content:i]
                    brace_count -= 1
        
        return full_text # Fallback if parsing fails

    # The pattern should match the outermost {num, plural, ...}
    # We can match {num, plural, [^}]*} but that fails on nested braces.
    # Given the complexity, let's process cell by cell using csv module.
    
    output = io.StringIO()
    reader = csv.reader(io.StringIO(content))
    writer = csv.writer(output)
    
    rows = list(reader)
    
    processed_count = 0
    
    for row in rows:
        new_row = []
        for cell in row:
            if "{num, plural," in cell:
                # Manual extraction of "other" block
                processed = cell
                try:
                    # Find "other {" position
                    idx = processed.find("other {")
                    if idx == -1: idx = processed.find("other{")
                    
                    if idx != -1:
                        # Start of the content inside "other {"
                        start_content = processed.find("{", idx) + 1
                        
                        # Walk forward to find matching closing brace
                        brace_depth = 1
                        end_content = -1
                        
                        for i in range(start_content, len(processed)):
                            if processed[i] == '{':
                                brace_depth += 1
                            elif processed[i] == '}':
                                brace_depth -= 1
                                if brace_depth == 0:
                                    end_content = i
                                    break
                        
                        if end_content != -1:
                            extracted = processed[start_content:end_content]
                            processed = extracted
                            processed_count += 1
                except:
                    pass # Keep original if error
                
                new_row.append(processed)
            else:
                new_row.append(cell)
        writer.writerow(new_row)
        
    with open(CSV_PATH, 'w', encoding='utf-8') as f:
        f.write(output.getvalue())
        
    print(f"Processed {processed_count} cells.")

if __name__ == "__main__":
    clean_csv()
