# Spiral Matrix
![alt text](imgs/image.png)


## Line of thought
這題的思路很單純，就是在 matrix 中根據螺旋形狀來將 item 放入 result array 之中。
一個常見的做法是控制四個指標： top, bottom, left, right 讓我們可以定義到路徑的正確位置，
同時我們透過這些指標的相互關係來判斷，何時需要進行轉彎的這個動作。

根據示意圖，我們總共有 4 次轉彎的動作，我們先從 top = 0 開始, 根據 `matrix[top][i]` 進行移動.
1. 碰到 Right 時，往下進行轉彎，移動路徑變成 `matrix[i][right]`.
2. 碰到 Bottom 時，往左進行轉彎，移動路徑變成 `matrix[bottom][i]`.
3. 碰到 Left 時，往上進行轉彎，移動路徑變成 `matrix[i][left]`.
4. 碰到 Top 時，往右進行轉彎，移動路徑變回 `matrix[top][i]`.


但由於走過的格子是不能再走的，因此我們要適時的對於4個指針進行加減，用於標示能夠移動的空間
- 當右行走完後, Top += 1, 用於代表前一個 Row 我們已經走完
- 當下行走完後, Right -= 1, 用於代表前一個 Column 我們已經走完
- 當左行走完後, Bottom -= 1, 用於代表前一個 Row 我們已經走完
- 當上行走完後, Left += 1, 用於代表前一個 Column 我們已經走完


## Solution
### Time O(MxN), Space O(1)
```python
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        
        top, bottom = 0, len(matrix) -1
        left, right = 0, len(matrix[0]) - 1

        while top <= bottom and left <= right:
            # Traverse Right
            for i in range(left, right + 1):
                res.append(
                    matrix[top][i]
                )
            top += 1

            # Traverse Down
            for i in range(top, bottom + 1):
                res.append(
                    matrix[i][right]
                )
            right-=1

            if top <= bottom:
                # Traverse Left
                for i in range(right, left -1, -1):
                    res.append(
                        matrix[bottom][i]
                    )
                bottom -= 1

            if left <= right:
                # Traverse Up
                for i in range(bottom, top -1, -1):
                    res.append(
                        matrix[i][left]
                    )
                left += 1

        return res
```

⚠️ 常見陷阱 (Trap): 如果矩陣是扁長的（例如 $1 \times 5$）或瘦高的（例如 $5 \times 1$），在執行完步驟 1 或 2 後，邊界可能已經交錯。如果不加 `if top <= bottom` 或 `if left <= right` 的判斷，程式會回頭重複讀取已經讀過的元素。