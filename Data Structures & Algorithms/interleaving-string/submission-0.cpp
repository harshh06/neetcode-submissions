class Solution {
public:
    bool solve(string& s1, string& s2, string& s3, int i, int j, vector<vector<int>>&dp) {
        if(i+j==s3.size() && i==s1.size() && j==s2.size()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool a = i<s1.size() && s1[i]==s3[i+j] && solve(s1,s2,s3,i+1,j,dp);
        bool b = j<s2.size() && s2[j]==s3[i+j] && solve(s1,s2,s3,i,j+1, dp);
        return dp[i][j] = a || b;
    }

    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return solve(s1,s2,s3,0,0, dp);
    }
};
