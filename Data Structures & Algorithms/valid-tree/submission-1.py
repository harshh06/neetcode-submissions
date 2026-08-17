class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:

        vis = [False] * n 
        mp = defaultdict(list)
        for a,b in edges:
            mp[a].append(b)
            mp[b].append(a)

        # def isCycle(v: int, parent: int) -> bool:
        #     vis[v] = True
        #     for u in mp[v]:
        #         if not vis[u]:
        #             if isCycle(u, v):
        #                 return True
        #         elif u != parent:
        #             return True
        #     return False

        # return False if isCycle(0, -1) else True


        q = deque([(0, -1)])
        vis[0] = True
        cnt = 0
        while q:
            v, par = q.popleft()
            cnt += 1
            for u in mp[v]:
                if not vis[u]:
                    q.append((u, v))
                    vis[u] = True
                elif u != par:
                    return False
        return True if cnt == n else False

