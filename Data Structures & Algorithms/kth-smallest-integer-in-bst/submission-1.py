# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def inorder(self, root: Optional[TreeNode]) :
        if not root or self.cnt <= 0:
            return root
        self.inorder(root.left)
        self.cnt -= 1
        if(self.cnt == 0):
            self.ans = root.val
            return
        self.inorder(root.right)

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        if not root:
            return root
        self.cnt = k
        self.ans = -1
        self.inorder(root)
        return self.ans