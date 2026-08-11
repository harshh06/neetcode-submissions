class Solution {
public:
    int solve(string& s, int i, vector<int>& dp) {
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int ways=0;
        if(i<s.size()-1) {
            if(s[i]=='1' || (s[i]=='2' && (s[i+1])<'7')) {
                ways += solve(s, i+1, dp);
                ways += solve(s, i+2, dp);
            } else ways += solve(s, i+1, dp);
        } else ways += solve(s, i+1, dp);
        return dp[i] = ways;
    }

    int numDecodings(string s) {
        int ans=0;
        vector<int>dp(s.size()+1, -1);
        return solve(s, 0, dp);
    }
};
