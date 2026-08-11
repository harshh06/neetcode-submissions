class Solution {
public:
    int dx[4] = {0,0,1,-1};
    int dy[4] = {-1,1,0,0};
    int solve(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>&dp) {
        int cnt=0;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=0;k<4;k++) {
            int x = dx[k]+i;
            int y = dy[k]+j;
            if(x>=0 && y>=0 && x<matrix.size() && y<matrix[0].size() && matrix[x][y]>matrix[i][j]) 
                cnt = max(cnt, 1+solve(matrix,x,y,dp));
        }
        return dp[i][j]=cnt;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        int ans=0;
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) {
                ans=max(ans,1+solve(matrix,i,j,dp));
            }
        return ans;
    }
};