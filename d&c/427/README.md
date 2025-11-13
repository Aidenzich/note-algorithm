# 427.  Construct Quad Tree

[leetcode](https://leetcode.com/problems/construct-quad-tree/description/?envType=study-plan-v2&envId=top-interview-150)

## Line of thought
這題是一題可以用 DFS 去建立樹結構的題目，核心概念是 Divide & Conquer.
要建立一個大的 Quad Tree, 其實可以拆解成建立多個小的 Quad Tree, 這是一個很直覺的 Divide & Conquer 題目。
而這題的難度在於你要怎麼定義 `dfs(x)` 數入的參數。

`dfs` 所需要處理的工作如下：
1. 判斷當前範圍的框框中的內容是否全部都是1或者全部都是0
2. 如果不是全部都一樣，那就需要進行切分的動作。反之，代表這個框框就是一個 Leaf.
3. 在切分時，要為 `topLeft`, `topLeft`, `bottomLeft`, `bottomRight` 都建立子樹

而為了要能夠在輸入的 Grid 的中，定義框框的範圍，我們需要使用三個參數： 當前 row, col, 跟長度
這樣子我們就可以定義要切的框框。然後我們就可以透過： row, col, 跟長度 去找出框框的座標
![alt text](<imgs/427.png>)
```
internal_node.topLeft = build(r, c, half_n)
internal_node.topRight = build(r, c + half_n, half_n)
internal_node.bottomLeft = build(r + half_n, c, half_n)
internal_node.bottomRight = build(r + half_n, c + half_n, half_n)
```



## Solution
```python
"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""

class Solution:
    def construct(self, grid: list[list[int]]) -> 'Node':    
        # r, c 是當前子格的左上角座標
        # n 是當前子格的邊長
        def build(r, c, n):                    
            first_val = grid[r][c]
            all_same = True
            for i in range(r, r + n):
                for j in range(c, c + n):
                    if grid[i][j] != first_val:
                        all_same = False
                        break
                if not all_same:
                    break
            
            # 如果值都相同，建立葉節點
            if all_same:
                # 注意：val 屬性是 boolean，所以要
                # 0 -> False, 1 -> True
                return Node(val=(first_val == 1), isLeaf=True)
            
            # 如果值不同，建立內節點並切四塊
            else:
                half_n = n // 2
                
                # 建立內節點
                # 根據題目，val 可以是 True 或 False，isLeaf 必須是 False
                internal_node = Node(val=True, isLeaf=False)
                
                # 遞迴呼叫，建立四個子節點
                internal_node.topLeft = build(r, c, half_n)
                internal_node.topRight = build(r, c + half_n, half_n)
                internal_node.bottomLeft = build(r + half_n, c, half_n)
                internal_node.bottomRight = build(r + half_n, c + half_n, half_n)
                
                return internal_node

        # 程式的進入點：從 (0, 0) 開始，處理整個 grid (邊長為 len(grid))
        return build(0, 0, len(grid))  
```