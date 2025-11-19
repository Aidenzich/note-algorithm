# Union Find (Disjoint Set Union)

Union Find 是一種用於管理不相交集合（Disjoint Sets）的資料結構。它主要用於解決圖論中的動態連通性問題，例如判斷兩個節點是否在同一個連通分量中，或者用於 Kruskal 演算法生成最小生成樹。

## 核心概念 (Concept)
![alt text](imgs/algorithm-union-find.png)
Union Find 維護了一組不相交的集合。每個集合由一個代表元素（Representative）來標識。

## 主要操作 (Operations)

Union Find 支持兩種主要操作：

1.  **`find(x)`**: 查找元素 `x` 所屬集合的代表元素。通常用於判斷兩個元素是否屬於同一個集合（即 `find(x) == find(y)`）。
2.  **`union(x, y)`**: 將元素 `x` 和元素 `y` 所屬的兩個集合合併為一個集合。

## 優化 (Optimizations)

為了提高效率，通常會使用以下兩種優化技術：

1.  **路徑壓縮 (Path Compression)**: 在執行 `find` 操作時，將路徑上的所有節點直接連接到根節點。這樣可以減小樹的高度，加速後續的查找操作。
2.  Optional. **按秩合併 (Union by Rank)** 或 **按大小合併 (Union by Size)**: 在執行 `union` 操作時，總是將較矮的樹（或節點較少的樹）合併到較高的樹（或節點較多的樹）下。這可以防止樹變得過高。

## 時間複雜度 (Time Complexity)
同時使用路徑壓縮和按秩合併後，單次操作的均攤時間複雜度為 $O(\alpha(n))$，其中 $\alpha$ 是反阿克曼函數（Inverse Ackermann function）。對於所有實際應用中的 $n$，$\alpha(n)$ 是一個非常小的常數（通常 $\le 4$），因此可以認為操作是近乎常數時間的。


## 使用時機
只要題目暗示「A 跟 B 有關，B 跟 C 有關，那 A 跟 C 也就有關」，這通常就是 Union-Find 的強項。
### 特徵 A：需要將元素「分組」或「合併集合」
> 關鍵字：Connected components (連通分量)、Merge (合併)、Group (分組)
這是最直覺的。題目會提到某些東西是屬於同一類的，或者要你把原本分開的東西合起來。

例子：
- 朋友圈：A 是 B 的朋友，B 是 C 的朋友，問總共有幾個朋友圈？（LeetCode 547. Number of Provinces）
- 島嶼數量：不過通常靜態地圖用 DFS/BFS，如果是動態填海造陸就要用 Union-Find。

### 特徵 B：查詢「兩點是否連通」或「是否在同一組」
題目會頻繁地問你：「X 和 Y 到底有沒有關係？」「X 和 Y 是不是同一國的？」

關鍵字：Is connected? (是否相連)、Path existence (路徑是否存在)。

- 優勢：Union-Find 的 find 操作極快，比 DFS/BFS 每次都要重新走迷宮快得多。

### 特徵 C：圖論中的「判斷成環 (Cycle Detection)」或「最小生成樹」
這比較偏算法題的標準套路。
例子：給你一堆邊，問你加上哪一條邊會讓這張圖變成有迴圈（Cycle）？（LeetCode 684. Redundant Connection）

邏輯：如果 A 和 B 已經是同一個老大了，你還想再連一條線，那肯定會變成迴圈。


## Python Template
### Without Rank
```python
class UnionFind:
    def __init__(self, n):
        # parent[i] 表示節點 i 的父節點
        # 初始時，每個節點的父節點是它自己
        self.parent = list(range(n))

        # count 表示連通分量的數量
        self.count = n

    def find(self, x):
        # 路徑壓縮：在查找過程中，將路徑上的所有節點直接指向根節點
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x != root_y:
            self.parent[root_y] = root_x
            self.count -= 1
            # 利用 union 函數的回傳值可以判斷成環問題。 如果 union(x, y) 回傳 False，表示 x 和 y 早就在一起了，這時候再連線就會形成環 (Cycle)
            return True
        return False

    def connected(self, x, y):
        return self.find(x) == self.find(y)
```


### With Rank
```python
class UnionFind:
    def __init__(self, n):
        # parent[i] 表示節點 i 的父節點
        # 初始時，每個節點的父節點是它自己
        self.parent = list(range(n))
        
        # rank[i] 表示以節點 i 為根的樹的高度（或近似高度）
        self.rank = [1] * n

        # count 表示連通分量的數量
        self.count = n

    def find(self, x):
        # 路徑壓縮：在查找過程中，將路徑上的所有節點直接指向根節點
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x != root_y:
            # 按秩合併：將較矮的樹合併到較高的樹下
            if self.rank[root_x] > self.rank[root_y]:
                self.parent[root_y] = root_x
            elif self.rank[root_x] < self.rank[root_y]:
                self.parent[root_x] = root_y
            else:
                self.parent[root_y] = root_x
                self.rank[root_x] += 1
            
            self.count -= 1
            return True
        return False

    def connected(self, x, y):
        return self.find(x) == self.find(y)
```


###  理論複雜度 (Theoretical Complexity)

假設進行 $m$ 次操作，節點數為 $n$：

| 組合方式 | 時間複雜度 | 說明 |
| :--- | :--- | :--- |
| **只有路徑壓縮 (Without Rank)** | **$O(m \log n)$** (最壞情況)<br>平均接近 $O(m \alpha(n))$ | 在極端刻意構造的測資下，樹的高度可能會達到 $\log n$，導致效率略微下降。但這種測資非常難構造。 |
| **路徑壓縮 + Rank (With Rank)** | **$O(m \alpha(n))$** | 這是數學上證明的最優解。$\alpha(n)$ 是反阿克曼函數，增長極慢，對於全宇宙的原子數量，$n$ 也不會讓 $\alpha(n)$ 超過 4。所以可視為 **$O(1)$**。 |
