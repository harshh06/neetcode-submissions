class Solution:
    def solve(self, board: List[List[str]]) -> None:
        n, m = len(board), len(board[0])

        vis = [[False]*m for _ in range(n)]
        directions = [(0,1), (1,0), (-1,0), (0,-1)]

        def on_boundary(i: int, j: int) -> bool:
            return i==0 or j==0 or i==n-1 or j==m-1
        
        def isValidCell(i: int, j: int) -> bool:
            return i>=0 and i<n and j>=0 and j<m
        
        def dfs(i: int, j: int) -> None:
            vis[i][j] = True
            board[i][j] = '#'
            for dx, dy in directions:
                x, y= dx+i, dy+j
                if isValidCell(x, y) and board[x][y] == 'O':
                    dfs(x, y)


        for i in range(n):
            for j in range(m):
                if board[i][j] == 'O' and on_boundary(i,j) and not vis[i][j]:
                    dfs(i, j)

        for i in range(n):
            for j in range(m):
                if board[i][j] == '#':
                    board[i][j] = 'O'
                else:
                    board[i][j] = 'X'
        