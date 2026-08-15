class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        n, m = len(heights), len(heights[0])
        pac, atl = set(), set()
        directions = [(0,1), (1,0), (-1,0), (0,-1)]
        visAtl = [ [False]*m for _ in range(n)] 
        visPac = [ [False]*m for _ in range(n)]

        def isValidCell(x: int, y: int, vis: List[List[bool]]) -> bool:
            return x>=0 and x<n and y>=0 and y<m and not vis[x][y]

        def dfs(i: int, j: int, s: Set[Tuple[int, int]], vis: List[List[bool]]) -> None:
            s.add((i, j))
            vis[i][j] = True
            for dx, dy in directions:
                x, y = i+dx, j+dy
                if isValidCell(x, y, vis) and heights[x][y] >= heights[i][j]:
                    dfs(x, y, s, vis)

        for i in range(n):
            dfs(i, 0, pac, visPac)
            dfs(i, m-1, atl, visAtl)
        for j in range(m):
            dfs(0, j, pac, visPac)
            dfs(n-1, j, atl, visAtl)

        res = []
        
        for coord in pac:
            if coord in atl:
                res.append([coord[0], coord[1]])
        
        return res
