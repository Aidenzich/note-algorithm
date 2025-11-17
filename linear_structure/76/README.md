# Leetcode 76. Minimum Window Substring

## Solution
```python
class Solution:
    def minWindow(self, s: str, t: str) -> str:        
        l = 0
        sCount, tCount = {}, {}
        matches = 0
        minLen = float("inf")
        res = ""

        for i in range(len(t)):
            tCount[t[i]] = tCount.get(t[i], 0) + 1
                        
        for r, c in enumerate(s):
            sCount[c] = sCount.get(c, 0) + 1
            
            if c in tCount and sCount[c] == tCount[c]:
                matches += 1

            while matches == len(tCount):                        
                                        
                if (r-l+1) < minLen:
                    minLen = r-l+1
                    res = s[l:r+1]


                sCount[s[l]] -= 1
                if s[l] in tCount and sCount[s[l]] < tCount[s[l]]:
                    matches -= 1

                l+=1


        return res
```

這題本身只在乎子字段是否滿足條件，而不用在乎當一個char 數量超出條件時的狀況，因此我們不用在 char 的 Counter 超出條件時就將 matches--. 