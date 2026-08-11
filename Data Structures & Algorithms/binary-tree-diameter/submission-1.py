# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def maxHeight(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        leftHeight = self.maxHeight(root.left)
        rightHeight = self.maxHeight(root.right)
        self.dia = max(self.dia, leftHeight + rightHeight)
        return max(leftHeight, rightHeight) + 1

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        self.dia = 0
        self.maxHeight(root)
        return self.dia