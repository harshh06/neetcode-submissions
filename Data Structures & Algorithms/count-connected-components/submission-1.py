class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        
        vis = [False]*n
        graph = defaultdict(list)
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
        cnt = 0
        
        def dfs(v: int) -> None:
            vis[v] = True
            for u in graph[v]:
                if not vis[u]:
                    dfs(u)

        for i in range(n):
            if not vis[i]:
                dfs(i)
                cnt += 1
        
        return cnt
        