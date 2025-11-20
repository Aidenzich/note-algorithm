# Kahn's Algorithm (Topological Sort)

[LeetCode 210. Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)

## Classify
Input: Directed Graph (Adjacency List/Matrix)
Strategy: BFS (Breadth-First Search), Greedy
Why:
1.  **Dependency Resolution**: 當任務之間存在依賴關係（例如：修課順序、編譯依賴），需要找到一個合法的執行順序時。
2.  **Cycle Detection**: 檢測有向圖中是否存在環。如果拓撲排序無法包含所有節點，則表示圖中存在環。
3.  **Topological Sort**: 需要將有向無環圖 (DAG) 的節點線性排序，使得對於每條邊 u->v，u 都在 v 之前。

## Line of thought
Kahn's Algorithm 的核心概念是利用 **入度 (In-degree)** 來判斷節點的依賴關係。

1.  **入度 (In-degree)**：指向該節點的邊的數量。如果一個節點的入度為 0，表示它沒有任何先決條件（或先決條件都已滿足），可以被處理。
2.  **隊列 (Queue)**：我們使用一個 Queue 來存儲所有入度為 0 的節點。這些是我們 BFS 的起點。

**演算法流程：**

1.  **初始化**：
    *   計算圖中所有節點的入度。
    *   將所有初始入度為 0 的節點加入 Queue。
2.  **BFS 遍歷**：
    *   當 Queue 不為空時：
        *   從 Queue 中取出一個節點 `u`。
        *   將 `u` 加入結果集（表示已修課/已處理）。
        *   遍歷 `u` 的所有鄰居 `v`（即 `u -> v` 的邊）：
            *   將 `v` 的入度減 1（因為 `u` 已經被移除了）。
            *   如果 `v` 的入度變為 0，表示 `v` 的所有依賴都已解決，將 `v` 加入 Queue。
3.  **循環檢測**：
    *   如果最終結果集的大小等於圖中節點的總數，則成功找到拓撲排序。
    *   如果結果集大小小於節點總數，說明圖中存在環 (Cycle)，無法進行拓撲排序。

**圖解範例：**

假設有課程：`0 -> 1`, `0 -> 2`, `1 -> 3`, `2 -> 3`

```text
初始狀態:
入度: [0: 0, 1: 1, 2: 1, 3: 2]
Queue: [0]

Step 1: Pop 0
結果: [0]
鄰居: 1, 2
更新入度: 1 (0->1 已移除) => 0, 2 (0->2 已移除) => 0
Queue: [1, 2]

Step 2: Pop 1
結果: [0, 1]
鄰居: 3
更新入度: 3 (1->3 已移除) => 1
Queue: [2]

Step 3: Pop 2
結果: [0, 1, 2]
鄰居: 3
更新入度: 3 (2->3 已移除) => 0
Queue: [3]

Step 4: Pop 3
結果: [0, 1, 2, 3]
鄰居: None
Queue: []

結束，結果為 [0, 1, 2, 3]
```

## Solution

### Time O(V + E), Space O(V + E)
- V: Vertices (Nodes), E: Edges
- Time: We visit every node and every edge once.
- Space: Adjacency list takes O(V+E), in-degree array takes O(V), queue takes O(V).

```python
from collections import deque

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # 1. Build Graph and Calculate In-degrees
        graph = [[] for _ in range(numCourses)]
        in_degree = [0] * numCourses
        
        for dest, src in prerequisites:
            graph[src].append(dest)
            in_degree[dest] += 1
            
        # 2. Initialize Queue with 0 in-degree nodes
        queue = deque([i for i in range(numCourses) if in_degree[i] == 0])
        result = []
        
        # 3. Process Queue
        while queue:
            node = queue.popleft()
            result.append(node)
            
            for neighbor in graph[node]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)
                    
        # 4. Check for Cycles
        if len(result) == numCourses:
            return result
        else:
            return [] # Cycle detected
```

## Traps & Notes
- ⚠️ **常見陷阱 (Trap)**: 忘記檢查結果長度是否等於節點總數。如果圖中有環，Queue 會變空但仍有節點未被訪問（因為它們的入度永遠不會變成 0）。
- ⚠️ **常見陷阱 (Trap)**: 建圖方向搞錯。`prerequisites = [[1, 0]]` 通常表示 `0 -> 1` (修完 0 才能修 1)，入度應該加在 `1` 上。
