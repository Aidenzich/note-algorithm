# Leetcode 105. Construct Binary Tree from Preorder and Inorder Traversal


## Solutions
### 1\.
```python
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder or not inorder:
            return None

        root_val = preorder[0]
        root = TreeNode(root_val)
        mid = inorder.index(root_val)

        root.left = self.buildTree(preorder[1 : 1 + mid], inorder[0 : mid])
        root.right = self.buildTree(preorder[1 + mid :], inorder[1+mid:])

        return root
```

### 2\. 
```python
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:            
        inorder_map = {val: i for i, val in enumerate(inorder)}             
        self.root_idx = 0        
        
        def build(l, r):            
            if l > r:
                return None
            
            root_val = preorder[self.root_idx]
            root = TreeNode(root_val)
                        
            self.root_idx += 1
                        
            mid = inorder_map[root_val]
                        
            root.left = build(l, mid - 1)
            root.right = build(mid + 1, r)
            
            return root

        
        return build(0, len(inorder) - 1)
```