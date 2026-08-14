class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        dir = [(0,1),(1,0),(-1,0),(0,-1)]
        n = len(grid)
        m = len(grid[0])
        maxArea = 0

        def dfs(i: int, j: int) -> int:
            grid[i][j] = 0
            area = 1
            for dx, dy in dir:
                x, y = i+dx, j+dy
                if x>=0 and x<n and y >=0 and y< m and grid[x][y] == 1:
                    area += dfs(x, y)
            return area

        for i in range (n):
            for j in range(m) :
                if grid[i][j] == 1:
                    area = dfs(i, j)
                    maxArea = max(maxArea, area)
        
        return maxArea