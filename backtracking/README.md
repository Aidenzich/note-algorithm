

#### Leetcode 17. Letter Combinations of a Phone Number
```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []

        mapping = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }
        
        results = []
        
        def dfs(index, state):
            if index == len(digits):
                results.append(state)                
                return 

            bag = mapping[digits[index]]

            for letter in bag:
                dfs(index + 1, state + letter)


        dfs(0, "")
        return results
```

#### Leetcode 46. Permutations
```python
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        results = []
        n = len(nums)
        visited = set()
        def dfs(state):
            if len(state) == n:
                results.append(state.copy())
                return 

            
            for i in range(n):                    
                if nums[i] not in visited:
                    state.append(nums[i])
                    visited.add(nums[i])

                    dfs(state)

                    # roll back
                    state.pop()
                    visited.remove(nums[i])


        dfs([])

        return results
```


#### Leetcode 77. Combinations
```python
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        results = []

        def dfs(curr, state):
            if len(state) == k:
                results.append(state.copy())
                return 
            
            bag = range(curr, n+1)
            # [2, 3, 4]
            for i in bag:
                state.append(i)

                dfs(i+1, state)
                # 3, 4, 5?

                state.pop()

        dfs(1, [])
        return results
```