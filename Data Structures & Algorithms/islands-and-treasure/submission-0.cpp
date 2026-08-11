class Solution {
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0) q.push({i,j});
            }
        }
        int len=1;
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                pair<int, int> cur = q.front();
                q.pop();
                vis[cur.first][cur.second] = 1;
                for(int k=0; k<4; k++) {
                    int x = cur.first + dx[k];
                    int y = cur.second + dy[k];
                    if(x>=0 && y>=0 && x<n && y<m && grid[x][y] == 2147483647) {
                        grid[x][y] = len;
                        q.push({x,y});
                    } 
                }
            }
            len++;
        }
    }
};
