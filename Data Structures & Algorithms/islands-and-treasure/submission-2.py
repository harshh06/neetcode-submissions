class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        dir = [(0,1), (1,0), (-1, 0), (0, -1)]
        q: Deque[Tuple[int, int]] = deque()
        n, m = len(grid), len(grid[0])
        vis = [[False]*(m) for _ in range(n)]
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0:
                    q.append((i,j))
                    vis[i][j] = True
        dist = 0
        while q:
            q_size = len(q)
            for _ in range(q_size):
                i, j = q[0]
                q.popleft()
                for dx, dy in dir:
                    x, y = i+dx, j+dy
                    if x>=0 and x<n and y>=0 and y<m and grid[x][y] == 2147483647 and vis[x][y]==False:
                        q.append((x, y))
                        vis[x][y] = True
                if dist and grid[i][j] == 2147483647:
                    grid[i][j] = dist
            dist += 1



            