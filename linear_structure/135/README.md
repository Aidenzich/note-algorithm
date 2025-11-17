# 135\. Candy
[link](https://leetcode.com/problems/candy/description/?envType=study-plan-v2&envId=top-interview-150)


## Classify
![alt text](<imgs/algorithm-Linear structure.png>)

這題 Input 是數字陣列，並且由於一個孩子會拿到多少糖果，與其左右邊的孩子有關，可以快速的推論出這題可以使用 `Two-Pass Algorithm` 來解題

## Line of thought
這題的解法核心思路在於，我們可以由左至右遍歷一次，先判斷孩子與其前一個孩子之間的分數關係，從而得到了一個只跟前一個孩子比較所能得到糖果數的結果

再來，我們可以透過從右至左再次遍歷，判斷孩子與後一個孩子之間的分數關係，從而得到了最終的糖果數。 我們可以透過 max 來判斷，是要比後一個位置的糖果數+1或者是保留由左至右時的糖果數，確保大的那個結果被留下來

這裡數據結構我們使用了以下技巧
```python
#    ------------->
#  1,[6,10,8,7,3,2]
#  ^
#    <-------------
#    [1,6,10,8,7,3],2
#                   ^
#                 (n-1)
```
- 分別由 index 為 `1` 與 `n-2` 的元素開始，由此可以讓由左至右能夠比較 `i-1`, 而由右至左可以比較 `i+1`，從而讓陣列之間的 item 可以兩兩對應，從而避免了指針操作的複雜性。
- 由左至右是從 `1` 開始: `range(1, n)`
- 由右至左是從 `n-2` 開始: `range(n-2, -1, -1)`



## Solution
```python
class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        candies = [1] * n

        for i in range(1, n):
            if ratings[i] > ratings[i-1]:
               candies[i] =  candies[i-1] + 1 
            

        for idx in range(n - 2, -1, -1):
            if ratings[idx] > ratings[idx+1]:
                candies[idx] = max(candies[idx+1] + 1 , candies[idx])

        return sum(candies)
```