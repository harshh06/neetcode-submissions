class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid)
        m = len(grid[0])
        dir = [(1,0),(0,1),(-1,0),(0,-1)]

        def dfs(row: int, col: int) -> int:
            grid[row][col] = "0"
            for dx, dy in dir:
                x, y = row+dx, col+dy
                if x>=0 and x<n and y>=0 and y<m and grid[x][y] == "1":
                    dfs(x,y)

        cnt = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == "1":
                    dfs(i, j)
                    cnt += 1
        return cnt