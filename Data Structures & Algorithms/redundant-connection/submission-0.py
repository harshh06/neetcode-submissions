class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        par = list(range(n+1))
        def find(x: int) -> int:
            if par[x] != x:
                par[x] = find(par[x])
            return par[x]

        for u, v in edges:
            root_u, root_v = find(u), find(v)
            if root_u == root_v:
                return [u, v]
            par[root_u] = root_v

        return []
