# TTP Compliance Automation Guide

This guide is designed for AI Agents (e.g., Gemini-3-Pro) to autonomously handle TTP Compliance tasks for Unity projects using the `ttp_manager.py` tool.

## 1. Prerequisites
- **Tool Script**: Ensure `/Users/bytedance/VO/QY/LBE/TTP/Unity/ttp_manager.py` is available.
- **Input File**: A raw TTP scan result file (e.g., `List` or `List.txt`) exported from the scanning platform.

## 2. Workflow Overview
The process consists of three main phases:
1.  **Initialization**: Parse raw data and generate initial reports.
2.  **Remediation (Loop)**: For each issue, analyze, fix (edit code), and mark as done.
3.  **Finalization**: Verify reports and output the Feishu-friendly summary.

---

## 3. Step-by-Step Instructions for Agent

### Phase 1: Initialization
**Command:**
```bash
python3 /Users/bytedance/VO/QY/LBE/TTP/Unity/ttp_manager.py --input <PATH_TO_LIST_FILE> --init
```
**Outcome:**
- Generates `*_Report.md`: The master tracking table.
- Generates `*_Report_Feishu.md`: The visual summary.
- **Action**: Read `*_Report.md` to understand the scope (count of issues, types).

### Phase 2: Remediation (Iterative)

**A. Handling "Code & Config" Issues (Type: Chinese / Domain)**
1.  **Read**: Select a Pending item from `*_Report.md`. Read the target file path.
2.  **Analyze**:
    - If `Chinese`: Identify the Chinese string mentioned in the `Details` column or file. Translate it to English.
    - If `Domain`: Replace the CN domain with a global domain (e.g., `developer.picoxr.com` -> `developer-global.pico-interactive.com`) or remove if unnecessary.
3.  **Edit**: Use `SearchReplace` tool to apply the fix in the source file.
4.  **Mark Done**:
    ```bash
    python3 /Users/bytedance/VO/QY/LBE/TTP/Unity/ttp_manager.py --input <PATH_TO_LIST_FILE> --mark-done <ISSUE_ID>
    ```

**B. Handling "Binary" Issues**
1.  **Analyze**: Check the `Ownership` and `Treatment Plan` in the report.
2.  **Action**:
    - **Second Party (PICO/Volc)**: Note "Push for Upgrade" (no code edit needed usually, unless upgrading SDK). Mark as done if the task is just to "Confirm Plan".
    - **Third Party**: Note "Exempt" or "Source Replacement".
    - *Note*: For this automated workflow, we primarily focus on classifying and planning. If actual binary replacement is needed, it requires user input (new SDK files).

### Phase 3: Finalization & Reporting
**Command:**
(Run automatically after `mark-done`, but can be forced)
```bash
python3 /Users/bytedance/VO/QY/LBE/TTP/Unity/ttp_manager.py --input <PATH_TO_LIST_FILE>
```
**Outcome:**
- The `*_Report_Feishu.md` file is updated with the latest status (✅/⏳).
- **Action**: Present the content of `*_Report_Feishu.md` to the user as the final deliverable.

---

## 4. Key Logic & Rules (Embedded in Script)

### 4.1 Dependency Ownership Classification
- **Second Party (Internal)**:
  - Keywords: `PICO`, `VolcEngine`, `ByteDance`, `Enterprise`, `ToB`
  - Definition: Components developed internally by the company but not by the current team.
- **Third Party (External)**:
  - Keywords: `Unity`, `DOTween`, `TubeRenderer`, `Jeffijoe`, `Microsoft`, `Plugins`
  - Definition: Open source software, commercial libraries, SDKs, tools from external vendors.
- **First Party (Self-developed)**:
  - Keywords: `Assets/Resources`, `Assets/Art`, `Tob XR Tools` (Context dependent)
  - Definition: Code maintained by the current team.

### 4.2 Detailed Treatment Rules (Reference)
**A. Binary & Dependencies**
1.  **Second Party (二方依赖)**:
    - **Rule**: Must be built in the TTP environment.
    - **Action**: Push the owner team to provide a TTP-compliant version (TTP bnpm/Maven).
    - **Status**: If version exists -> Upgrade. If not -> Push for remediation.
2.  **Third Party (三方依赖)**:
    - **Rule**: Verify source and license.
    - **Action**:
        - Option A: Find source code -> Modify to be compliant -> Integrate as source.
        - Option B: Apply for exemption (must prove source URL/License).
3.  **Other External**:
    - Algorithms/Models: Treat as external dependencies, request compliant versions from algorithm teams.

**B. Content Audit**
1.  **Chinese Characters (中文)**:
    - **Rule**: Translate all UI/Log/Comments to English.
    - **Exception**: If content is useless/deprecated -> Delete directly.
    - **Sensitive Words**: Remove immediately (e.g., specific brand names restricted in US).
2.  **Domains (域名)**:
    - **Rule**: Remove all CN (China) domains.
    - **Action**: Replace with US/Global domains (e.g., `.com`, `.net`). Ensure at least one default US domain exists.

## 5. Example Interaction
**User**: "Here is the list file `/path/to/List`. Fix the Chinese issues."
**Agent**:
1. Run `python3 ttp_manager.py --input /path/to/List --init`
2. Read `List_Report.md`.
3. Loop through "Chinese" items:
   - Read file `A.cs`.
   - `SearchReplace` "中文" -> "English".
   - Run `python3 ttp_manager.py --input /path/to/List --mark-done 12345`
4. Show `List_Report_Feishu.md`.
