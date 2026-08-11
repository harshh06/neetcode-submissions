# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        dq = deque([])
        order = []
        dq.append(root)
        while len(dq) > 0:
            curLen = len(dq)
            tmpList = []
            for i in range(curLen):
                front = dq[0]
                dq.popleft()
                tmpList.append(front.val)
                if front.left:
                    dq.append(front.left)
                if front.right:
                    dq.append(front.right)
            order.append(tmpList)
        return order

