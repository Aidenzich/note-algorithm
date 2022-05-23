# 685
https://leetcode.com/problems/redundant-connection-ii/
## Tips
`Union Find`

## Unstanding Question
![case_example](./0.png)

## SOP
1. When a node has plural parents, save the previous one as answer1 and the later one as answer2, and then we remove the latter edges by marking the edge's value as -1.
2. Traverse the edges, and use `Union Find` to determine which edge will cause a ring in the graph. If there is no edge satisfy the above condition, the answer is answer2, otherwise answer1.



## Reference
- [Union Find](https://www.youtube.com/watch?v=ayW5B2W9hfo&t=1s)
- https://www.youtube.com/watch?v=lnmJT5b4NlM&t=6s
