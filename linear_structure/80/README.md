# Leetcode 80. Remove Duplicates from Sorted Array II

![alt text](imgs/image.png)

## Classify
Array, Two Pointers
思路：這題要求原地修改數組，且數組已排序。我們需要保留最多兩個重複項。這意味著我們需要一個指針來讀取當前元素 (`read`)，另一個指針來寫入符合條件的元素 (`write`)。因為是原地修改，且寫入位置總是小於等於讀取位置，所以雙指針是合適的選擇。

## Line of thought
題目要求我們刪除排序數組中的重複項，使得每個元素最多出現兩次，並返回新的長度。
因為數組是排序的，重複的元素會聚在一起。

我們可以使用雙指針策略：
- `read` 指針：用於遍歷數組，讀取當前元素。
- `write` 指針：指向下一個應該寫入合法元素的位置。

流程圖邏輯（Flowchart）：
1.  **初始化**：我們設定 `write = 0`，並且因為允許最多兩個重複，我們可以設一個變量 `k = 2`。
2.  **遍歷**：讓 `read` 從 0 開始遍歷到數組結束。
3.  **判斷與決策**：
    - 我們需要決定當前 `nums[read]` 是否應該被保留。
    - 判斷條件是：`write < 2` (前兩個元素總是保留) 或者 `nums[write-2] != nums[read]` (當前元素與倒數第二個寫入的元素不同)。
    - **如果符合條件 (True)**：
        - 這表示 `nums[read]` 是合法的（它不是第三個重複項）。
        - 我們執行寫入：`nums[write] = nums[read]`。
        - 然後移動寫入指針：`write += 1`。
    - **如果不符合條件 (False)**：
        - 這表示 `nums[read]` 與 `nums[write-2]` 相同，且因為數組有序，它也一定與 `nums[write-1]` 相同。這意味著我們已經有兩個該元素了，所以這是第三個，應該丟棄。
        - 我們什麼都不做，直接進入下一次循環（`read` 自動加 1）。
4.  **結束**：遍歷完成後，`write` 的值就是新數組的長度。

## Solution
```python
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        write = 0
        k = 2

        for read in range(len(nums)):
            
            if write < k or nums[write-k] != nums[read]:
                nums[write] = nums[read]
                write += 1
        
        return write
```


