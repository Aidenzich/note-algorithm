# Algorithm Note Writing Guidelines

This document serves as the source of truth for creating new algorithm notes in this repository. All future notes must strictly adhere to this format.

## 1. File Structure & Location
- Each problem gets its own directory, typically named after the problem ID (e.g., `54`, `135`).
- The note file is always named `README.md`.
- Images should be placed in an `imgs/` subdirectory if possible, or referenced correctly.

## 2. Content Structure

The `README.md` must contain the following sections in order:

### 2.1 Header
- Format: `# [Problem ID]. [Problem Name]`
- Example: `# 135. Candy`

### 2.2 Link
- A direct link to the LeetCode problem.
- Format: `[link](URL)`

### 2.3 Classify
- **Header**: `## Classify`
- **Image**: Include a classification image if applicable.
  - Format: `![alt text](<imgs/image_name.png>)`
- **Description**: Briefly describe the input format and the high-level algorithmic strategy (e.g., "Two-Pass Algorithm", "Sliding Window"). You also need to explain why you classify this problem into this category.

### 2.4 Line of thought (Core Section)
- **Header**: `## Line of thought`
- **Language**: Traditional Chinese (繁體中文).
- **Content**:
  - Explain the core logic and intuition.
  - **Visual Aids**: Use ASCII art, pseudo-code blocks, or diagrams to explain pointer movements, array correspondences, or state changes.
  - **Step-by-Step**: Use numbered lists for sequential logic (e.g., spiral traversal steps).
  - **Variables**: Clearly define key variables (e.g., `top`, `bottom`, `left`, `right`) and their update conditions.

### 2.5 Solution
- **Header**: `## Solution`
- **Complexity**: (Optional) `### Time O(X), Space O(Y)`
- **Code**:
  - Language: Python
  - Wrap in a `python` code block.
  - Include the full `class Solution` implementation.

### 2.6 Traps & Notes (If applicable)
- **Format**: `⚠️ 常見陷阱 (Trap): [Description]`
- **Content**: Mention edge cases, common mistakes, or boundary conditions to watch out for.

## 3. Style Guidelines
- **Tone**: Technical, explanatory, focusing on "Why" and "How".
- **Formatting**: Use Markdown features (lists, bold text, code blocks) to improve readability. Avoid walls of text.
