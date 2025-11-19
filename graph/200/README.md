# 200. Number of Islands

[link](https://leetcode.com/problems/number-of-islands/)

## Classify
這題雖然輸入是 Matrix，但本質上屬於 Graph Traversal 的範疇。

我們可以將這個二維網格視為一個無向圖 (Undirected Graph)：
- **節點 (Nodes)**：網格中的每一個格子 `(r, c)` 都是一個節點。
- **邊 (Edges)**：如果兩個相鄰（上下左右）的格子都是 `'1'` (陸地)，則它們之間存在一條邊。

題目要求的「島嶼數量」，在圖論中對應的就是 **連通分量 (Connected Components)** 的數量。
我們需要遍歷這個圖，找出有多少個獨立的連通區域。這是一個典型的圖遍歷問題，非常適合使用 DFS (深度優先搜尋) 或 BFS (廣度優先搜尋) 來解決。

## Line of thought
這題的核心思路是遍歷整個網格。
1. 我們使用兩個迴圈遍歷網格的每一個格子 `grid[r][c]`。
2. 當我們遇到一個 `'1'` (陸地) 時，表示我們發現了一個新的島嶼。此時將島嶼計數器 `count` 加 1。
3. 為了避免重複計算同一個島嶼的其他部分，我們需要立即啟動一個遍歷算法 (DFS 或 BFS)。
4. 從當前的 `'1'` 出發，將所有與其相連的 `'1'` 都標記為已訪問。標記的方法可以直接將 `grid[r][c]` 修改為 `'0'`，這樣就不需要額外的 `visited` 空間。
5. 遍歷結束後，繼續外層的迴圈，尋找下一個尚未被訪問的 `'1'`。

## Solution
### Time O(M * N), Space O(M * N)
```python
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
            
        m, n = len(grid), len(grid[0])
        count = 0
        
        def dfs(r, c):
            # Base case: check boundaries and if current cell is water ('0')
            if r < 0 or c < 0 or r >= m or c >= n or grid[r][c] == '0':
                return
            
            # Mark as visited by changing '1' to '0'
            grid[r][c] = '0'
            
            # Visit all 4 adjacent neighbors
            dfs(r + 1, c)
            dfs(r - 1, c)
            dfs(r, c + 1)
            dfs(r, c - 1)
            
        for r in range(m):
            for c in range(n):
                if grid[r][c] == '1':
                    count += 1
                    dfs(r, c)
                    
        return count
```