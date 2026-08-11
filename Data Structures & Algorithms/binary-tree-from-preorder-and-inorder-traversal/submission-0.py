# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def build(self, preorder: List[int], st: int, end: int) -> Optional[TreeNode]:
        if st>end:
            return None
        root = TreeNode(preorder[self.idx])
        self.idx += 1
        if(st == end) :
            return root;
        pos = self.indexMap[root.val]
        root.left = self.build(preorder, st, pos-1)
        root.right = self.build(preorder, pos + 1, end)

        return root

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        self.indexMap = {}
        for i in range(len(preorder)):
            self.indexMap[inorder[i]] = i
        self.idx = 0
        root = self.build(preorder, 0, len(preorder)-1)
        return root

