class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        fresh = 0
        q = deque()
        n, m = len(grid), len(grid[0])
        vis = [[False]*m for _ in range(n)]
        dir = [(0,1), (1,0), (-1,0), (0,-1)]
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    q.append((i, j))
                    vis[i][j] = True
                if grid[i][j] == 1:
                    fresh += 1
        
        def isValidCell(x: int, y: int) -> bool:
            return x>=0 and x<n and y>=0 and y<m and not vis[x][y] and grid[x][y] == 1

        time = 0

        while q:
            q_size = len(q)
            if not fresh:
                return time
            for _ in range(q_size):
                i, j = q.popleft()
                for dx, dy in dir:
                    x, y = i+dx, j+dy
                    if isValidCell(x, y):
                        q.append((x, y))
                        vis[x][y] = True
                        fresh -= 1
            time += 1
        return -1 if fresh else 0
                