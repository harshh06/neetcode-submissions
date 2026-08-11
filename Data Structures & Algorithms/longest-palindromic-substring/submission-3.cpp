class Solution {
public:
    bool isPal(int i, int j, string& s, vector<vector<int>>& dp) {
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = s[i] == s[j] && isPal(i+1, j-1, s, dp);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int ml=-1,mr=-1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++) {
                if(j-i>=mr-ml&& isPal(i,j,s,dp)) {
                    mr=j;
                    ml=i;
                }
            }
        }
        return s.substr(ml,mr-ml+1);
    }

};
