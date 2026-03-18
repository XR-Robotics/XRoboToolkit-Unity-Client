import os
import sys
import re
import argparse

# Configuration
# ------------------------------------------------------------------------------
DEFAULT_REPORT_SUFFIX = "_Report.md"
DEFAULT_FEISHU_SUFFIX = "_Report_Feishu.md"

# Classification Rules
# ------------------------------------------------------------------------------
def get_ownership(path):
    path_lower = path.lower().replace("\\", "/")
    
    # Second Party (Internal)
    if any(k in path_lower for k in ["pico", "pxr", "volcengine", "bytedance", "tob_api", "enterprise"]):
        if "enterprise" in path_lower: return "Second Party (PICO Enterprise)"
        if "volcengine" in path_lower: return "Second Party (VolcEngine)"
        return "Second Party (PICO)"
        
    # Third Party
    if any(k in path_lower for k in ["com.unity", "dotween", "tuberenderer", "jeffijoe", "microsoft", "third party", "plugins"]):
        if "unity" in path_lower: return "Third Party (Unity)"
        if "dotween" in path_lower: return "Third Party (DOTween)"
        return "Third Party"
        
    # First Party (Self-developed)
    if any(k in path_lower for k in ["tob xr tools", "assets/resources", "assets/art", "assets/space scanning"]):
        return "First Party (Self-developed)"
        
    # Config/System
    if any(k in path_lower for k in ["manifest.json", "packages-lock.json", "projectsettings"]):
        return "Config File"
        
    return "Unknown"

def get_treatment(issue_type, ownership, path):
    if issue_type == "chinese":
        return "Translate to English"
    if issue_type == "domain":
        return "Replace with Global Domain / Remove"
    if issue_type == "binary_check":
        if "Second Party" in ownership: return "Push for TTP Version / Upgrade"
        if "Third Party" in ownership: return "Exempt (Prove Source) / Modify Source"
        if "First Party" in ownership: return "Modify Source / Delete"
    return "Review"

# Manager Class
# ------------------------------------------------------------------------------
class TTPManager:
    def __init__(self, list_file):
        self.list_file = list_file
        self.base_dir = os.path.dirname(list_file)
        self.base_name = os.path.splitext(os.path.basename(list_file))[0]
        self.report_file = os.path.join(self.base_dir, self.base_name + DEFAULT_REPORT_SUFFIX)
        self.feishu_file = os.path.join(self.base_dir, self.base_name + DEFAULT_FEISHU_SUFFIX)
        self.data = []
        self.completed_ids = set()

    def load_data(self):
        """Parses the raw List file (TSV/CSV)"""
        print(f"Loading data from {self.list_file}...")
        try:
            # First, try to load existing completion status if report exists
            if os.path.exists(self.report_file):
                with open(self.report_file, 'r') as f:
                    content = f.read()
                    # Find all IDs marked as Completed
                    # Pattern: | 12345678 | Completed |
                    matches = re.findall(r'\|\s*(\d{8})\s*\|\s*Completed\s*\|', content)
                    self.completed_ids.update(matches)
            
            with open(self.list_file, 'r') as f:
                lines = f.readlines()
            
            self.data = []
            for line in lines:
                parts = line.strip().split('\t')
                # Check for valid ID row (starts with 856... or similar ID format)
                if len(parts) > 10 and parts[0].isdigit() and len(parts[0]) >= 8:
                    item_id = parts[0].strip()
                    item = {
                        "id": item_id,
                        "status": "Completed" if item_id in self.completed_ids else "Pending",
                        "type": parts[4].strip(), # e.g. chinese, domain, binary_check
                        "rule": parts[5].strip(), # e.g. 中文, .so, etc.
                        "path": parts[10].strip(), # Full path usually at col 10
                        "details": parts[14].strip() if len(parts) > 14 else "" # Code snippet or details
                    }
                    
                    # Analysis
                    item["ownership"] = get_ownership(item["path"])
                    item["plan"] = get_treatment(item["type"], item["ownership"], item["path"])
                    
                    self.data.append(item)
            print(f"Loaded {len(self.data)} items.")
        except Exception as e:
            print(f"Error loading data: {e}")

    def mark_completed(self, item_ids):
        """Marks specific IDs as completed"""
        for iid in item_ids:
            self.completed_ids.add(iid)
            for item in self.data:
                if item["id"] == iid:
                    item["status"] = "Completed"
        print(f"Marked {len(item_ids)} items as completed.")

    def generate_reports(self):
        """Generates both Markdown reports"""
        self._write_main_report()
        self._write_feishu_report()

    def _write_main_report(self):
        lines = [f"# TTP Compliance Report ({self.base_name})", ""]
        
        # Section 1: Code/Text Issues
        lines.append("## 1. Code & Config Issues (Chinese/Domain)")
        lines.append("| ID | Status | Type | File Path | Ownership | Treatment Plan | Details |")
        lines.append("|---|---|---|---|---|---|---|")
        
        code_items = [i for i in self.data if i["type"] in ["chinese", "domain"]]
        for item in code_items:
            # Escape pipes in details
            details = item["details"].replace("|", " ").replace("\n", " ")[:50] # Truncate details
            lines.append(f"| {item['id']} | {item['status']} | {item['type']} | `{item['path']}` | {item['ownership']} | {item['plan']} | {details} |")
            
        lines.append("")
        
        # Section 2: Binary Issues
        lines.append("## 2. Binary Issues")
        lines.append("| ID | Status | File Type | File Path | Ownership | Treatment Plan |")
        lines.append("|---|---|---|---|---|---|")
        
        bin_items = [i for i in self.data if i["type"] == "binary_check"]
        for item in bin_items:
            lines.append(f"| {item['id']} | {item['status']} | {item['rule']} | `{item['path']}` | {item['ownership']} | {item['plan']} |")
            
        lines.append("")
        
        # Section 3: Dependencies Summary
        lines.append("## 3. External Dependencies Summary")
        lines.append("| Component | Ownership | Count | Plan |")
        lines.append("|---|---|---|---|")
        
        deps = {}
        for item in self.data:
            if "Second Party" in item["ownership"] or "Third Party" in item["ownership"]:
                key = item["ownership"] # Group by ownership roughly or deduce component name
                # Simple component grouping
                comp = "Unknown"
                if "PICO" in item["path"]: comp = "PICO SDK"
                elif "DOTween" in item["path"]: comp = "DOTween"
                elif "Unity" in item["path"]: comp = "Unity"
                else: comp = item["ownership"]
                
                if comp not in deps: deps[comp] = {"count": 0, "plan": item["plan"], "ownership": item["ownership"]}
                deps[comp]["count"] += 1
            else:
                # Add Unknown/First Party for completeness if needed, or skip
                pass
        
        for comp, info in deps.items():
            lines.append(f"| {comp} | {info['ownership']} | {info['count']} | {info['plan']} |")
            
        with open(self.report_file, 'w') as f:
            f.write("\n".join(lines))
        print(f"Generated {self.report_file}")

    def _write_feishu_report(self):
        lines = []
        lines.append(f"# TTP Compliance Report - Feishu View ({self.base_name})")
        
        def write_item(item):
            icon = "✅" if item["status"] == "Completed" else "⏳"
            lines.append(f"- {icon} **{item['id']}** ({item['status']})")
            lines.append(f"  - Type: {item['type']}")
            lines.append(f"  - Path: `{item['path']}`")
            lines.append(f"  - Ownership: {item['ownership']}")
            lines.append(f"  - Plan: {item['plan']}")
            if item['details']:
                # Clean details
                det = item['details'].replace('|', ' ').strip()
                lines.append(f"  - Details: {det}")

        lines.append("")
        lines.append("## Code Issues")
        for item in [i for i in self.data if i["type"] in ["chinese", "domain"]]:
            write_item(item)
            
        lines.append("")
        lines.append("## Binary Issues")
        for item in [i for i in self.data if i["type"] == "binary_check"]:
            write_item(item)
            
        with open(self.feishu_file, 'w') as f:
            f.write("\n".join(lines))
        print(f"Generated {self.feishu_file}")

# Main Entry
# ------------------------------------------------------------------------------
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="TTP Compliance Task Manager")
    parser.add_argument("--input", help="Path to the raw List file")
    parser.add_argument("--init", action="store_true", help="Initialize reports from List file")
    parser.add_argument("--mark-done", nargs="+", help="Mark IDs as completed")
    
    args = parser.parse_args()
    
    # Default path if running in this specific context context
    list_path = args.input if args.input else "/Users/bytedance/VO/QY/LBE/TTP/Unity/List"
    
    if not os.path.exists(list_path):
        print(f"Error: Input file {list_path} not found.")
        sys.exit(1)
        
    manager = TTPManager(list_path)
    manager.load_data()
    
    if args.mark_done:
        manager.mark_completed(args.mark_done)
        
    # Always regenerate reports to reflect current state
    manager.generate_reports()
