# 399. Evaluate Division

## Classify
Graph, DFS, Union Find

這題之所以被分類為 **Graph**，是因為變數之間的除法關係可以被視為節點 (Node) 與邊 (Edge) 的關係。
- **Graph**: 每一個變數是一個節點，`a / b = k` 代表從 `a` 到 `b` 有一條權重為 `k` 的邊。
- **DFS/BFS**: 當我們要求解 `a / c` 時，等同於尋找從 `a` 到 `c` 的路徑，並將路徑上的權重相乘。這正是圖論中路徑搜尋的典型應用。
- **Union Find**: 另一個思路是利用 Union Find 將有關係的變數合併在同一個集合中，並維護每個節點相對於根節點的倍率。這樣可以在查詢時快速判斷兩個變數是否在同一個集合，並計算它們的比值。

## Line of thought
這題可以被建模成一個圖論問題 (Graph Problem)。
我們可以將每一個變數視為圖中的一個節點 (Node)，而除法關係 `a / b = k` 則可以視為一條從 `a` 指向 `b` 的有向邊 (Directed Edge)，其權重 (Weight) 為 `k`。
同時，因為 `a / b = k` 隱含了 `b / a = 1/k`，所以我們也需要建立一條從 `b` 指向 `a` 的邊，權重為 `1/k`。

當我們要求解 `x / y` 時，實際上就是在圖中尋找一條從節點 `x` 到節點 `y` 的路徑。
如果路徑存在，則路徑上所有邊的權重乘積即為答案。
例如：`a / b = 2.0`, `b / c = 3.0`，則 `a -> b` (2.0), `b -> c` (3.0)。
求 `a / c` 即為 `a -> b -> c`，結果為 `2.0 * 3.0 = 6.0`。

具體實作上，我們可以使用 DFS (深度優先搜尋) 或 BFS (廣度優先搜尋) 來尋找路徑。
為了避免在圖中無限循環，我們需要一個 `visited` 集合來記錄已經訪問過的節點。

針對每一個 query `(C, D)`：
1. 如果 `C` 或 `D` 不在圖中，直接返回 `-1.0`。
2. 如果 `C == D`，返回 `1.0`。
3. 否則，從 `C` 開始進行 DFS/BFS 搜尋 `D`，並計算路徑權重積。如果找不到路徑，返回 `-1.0`。

## Solution
### Time O(N * (V+E)), Space O(V+E)
其中 N 是 queries 的數量，V 是變數的數量，E 是 equations 的數量。
每次 query 最壞情況下需要遍歷整個圖。

```python
class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        # Build the graph
        graph = collections.defaultdict(dict)
        for (x, y), val in zip(equations, values):
            graph[x][y] = val
            graph[y][x] = 1.0 / val
            
        def dfs(x, y, visited):
            if x not in graph or y not in graph:
                return -1.0
            
            if y in graph[x]:
                return graph[x][y]
            
            visited.add(x)
            for neighbor, weight in graph[x].items():
                if neighbor not in visited:
                    res = dfs(neighbor, y, visited)
                    if res != -1.0:
                        return weight * res
            
            return -1.0

        res = []
        for q in queries:
            res.append(dfs(q[0], q[1], set()))
            
        return res
```

### Time O((N+E) * log*(V)), Space O(V) Union Find Solution
使用 Union Find 可以更快速地處理查詢，特別是當查詢數量很大時。
我們需要維護每個節點到其根節點的倍率 (weight)。

```python
class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        parent = {}
        weight = {} # weight[x] = x / parent[x]

        def find(x):
            if x not in parent:
                parent[x] = x
                weight[x] = 1.0
            
            if parent[x] != x:
                origin_parent = parent[x]
                parent[x], w = find(parent[x])
                weight[x] *= w
            
            return parent[x], weight[x]

        def union(x, y, val):
            rootX, wX = find(x)
            rootY, wY = find(y)
            
            if rootX != rootY:
                parent[rootX] = rootY
                # x / y = val
                # x = wX * rootX
                # y = wY * rootY
                # wX * rootX / (wY * rootY) = val
                # rootX / rootY = val * wY / wX
                weight[rootX] = val * wY / wX

        # Build the graph
        for (x, y), val in zip(equations, values):
            union(x, y, val)
            
        res = []
        for x, y in queries:
            if x not in parent or y not in parent:
                res.append(-1.0)
                continue
            
            rootX, wX = find(x)
            rootY, wY = find(y)
            
            if rootX != rootY:
                res.append(-1.0)
            else:
                # x / y = (x / rootX) / (y / rootY) = wX / wY
                res.append(wX / wY)
                
        return res
```
