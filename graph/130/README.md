# 130. Surrounded Regions

[link](https://leetcode.com/problems/surrounded-regions/)

## Classify
這題同樣也是以 Matrix 為輸入，但本質上屬於 Graph Traversal 的題型。
具體來說，這是一個關於 **連通分量 (Connected Components)** 的問題，但有一個特殊的條件：我們只關心那些 **沒有** 連接到邊界的連通分量。

## Line of thought
這題的重點在於，要怎麼樣判斷哪些 'O' 是被 'X' 包圍的？
直觀的想法可能比較難實現，因為要判斷一個區域是否被包圍，需要檢查它四周是否都是 'X'，而且這個區域可能形狀很不規則。

**逆向思考 (Reverse Thinking)**：
與其找出哪些 'O' 被包圍，不如找出 **哪些 'O' 沒有被包圍**。
1. 任何連接到網格邊界 (Boundary) 的 'O'，一定不會被 'X' 包圍。
2. 與這些邊界上的 'O' 相連的所有 'O'，也都不會被包圍。

因此，我們的策略如下：
1. **標記安全區域**：遍歷網格的四條邊界。如果遇到 'O'，就從這個位置開始進行 DFS 或 BFS 遍歷，將所有相連的 'O' 都標記為一個特殊字符（例如 'A'），表示這些是「安全」的，不應該被翻轉。
2. **翻轉其餘區域**：遍歷整個網格。
    - 如果遇到 'O'：這表示它沒有被標記為安全，說明它被 'X' 包圍了，將其修改為 'X'。
    - 如果遇到 'A'：這表示它是安全的 'O'，將其還原回 'O'。

## Solution
### Time O(M * N), Space O(M * N)
```python
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        if not board:
            return
            
        rows, cols = len(board), len(board[0])
        
        def dfs(r, c):
            # Base case: check boundaries and if current cell is not 'O'
            if r < 0 or c < 0 or c >= cols or r >= rows or board[r][c] != 'O':
                return 

            # Mark as safe
            board[r][c] = "A"

            # Visit neighbors
            dfs(r+1, c)
            dfs(r-1, c)
            dfs(r, c+1)
            dfs(r, c-1)

        # 1. Traverse boundaries and mark safe regions
        for i in range(rows):
            dfs(i, 0)
            dfs(i, cols-1)

        for i in range(cols):
            dfs(0, i)
            dfs(rows-1, i)

        # 2. Flip captured regions and restore safe regions
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == "A":
                    board[i][j] = "O"
                elif board[i][j] == "O":
                    board[i][j] = "X"
```