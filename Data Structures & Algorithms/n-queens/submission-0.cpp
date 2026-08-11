class Solution {
public:
    bool isValid(vector<string> cur, int r, int c, int n) {
        int i=r-1;
        while(i >= 0) {
            if(cur[i][c] == 'Q') return false;
            i--;
        }
        int j=c-1;
        while(j>=0) {
            if(cur[r][j] == 'Q') return false;
            j--;
        }
        i=r-1, j=c-1;
        while(i >=0 && j>= 0) {
            if(cur[i][j] == 'Q') return false;
            i--; j--;
        }
        i=r-1; j=c+1;
        while(i >= 0 && j < n) {
            if(cur[i][j] == 'Q') return false;
            i--; j++;
        }
        return true;
    }

    void solve(vector<vector<string>>& ans, vector<string>& cur, int n, int r) {
        if(r == n) {
            ans.push_back(cur);
            return;
        }
        for(int c=0; c<n; c++) {
            if(isValid(cur, r, c, n)) {
                cur[r][c] = 'Q';
                solve(ans, cur, n, r+1);
                cur[r][c] = '.';
            }
        }
    } 

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> cur(n, string(n, '.'));
        solve(ans, cur, n, 0);
        return ans;
    }
};
