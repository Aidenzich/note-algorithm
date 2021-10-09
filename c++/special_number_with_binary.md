# Calculate Special Number with Binary
## Special Number
> *A number is said to be special number when the sum of factorial of its digits is equal to the number itself.*
---
### Way of thinking
- We observe that :
    the Special values can be converted into :
    $$
        base^n + base^{n-1} + ...+base^0
    $$
- Binaray
    | index | n | n-1 | ... | 1 | 0|
    |---|---|---|---|---|---|
    | num | 1 | 1 | ... | 1 | 1 |

- 𝑘 can be write into binary system:
    | index | 3 | 2 | 1 | 0 |
    |---|---|---|---|---|
    | k=12 | 1 | 1 | 0 | 0 |
    | k=13 | 1 | 1 | 0 | 1 |
    - in c++, you can use ```(k & (1<<i))``` to find the position of biggest power of base
        > `x & 1` produces a value that is either 1 or 0, depending on the least significant bit of `x`: if the last bit is 1, the result of `x & 1` is 1; otherwise, it is 0.
    - e.g. When k =12, ```(k & (1<< i))``` will be true if `i=2` and `i=3`
- And 𝑘-th Special Number of base value can be calculate like:
    | *Power of base* | base^3 | base^2 | base^1 | base^0 |
    |---|---|---|---|---|
    | k=1 | 0 | 0 | 0 | 1 |
    | ... | ... | ... | ... | ... |
    | k=12 | 1 | 1 | 0 | 0 |
    | k=13 | 1 | 1 | 0 | 1 |
    | ... | ... | ... | ... | ... |
    
    
    - if `base = 2`, we can figure out that 12th Special Number is $2^2 + 2^3$, which is `12`.
    - Same as above, if base = 2 then the 12th Specail Number is $3^2 + 3^3 = 36$ 

## Programming Example:
- [Codeforce 1594 Problem B](./practice/codeforce/1594/b.cpp)
- [OJ 1006 Problem 2](./practice/oj1006/q2_a1.cpp)