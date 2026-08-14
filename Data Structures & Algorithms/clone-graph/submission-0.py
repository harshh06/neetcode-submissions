"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if node is None:
            return node
        newNode = Node(node.val)
        
        mp: Dict[int, 'Node'] = {} 

        def dfs(node: Optional['Node'], newNode: Optional['Node']) -> None:
            mp[node.val] = newNode
            for neigh in node.neighbors:
                if neigh.val in mp:
                    newNode.neighbors.append(mp[neigh.val])
                else:
                    newNeigh = Node(neigh.val)
                    newNode.neighbors.append(newNeigh)
                    dfs(neigh, newNeigh)

        dfs(node, newNode)
        return newNode
