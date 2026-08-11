class Solution {
public:

    int solve(string& s, unordered_set<string>& ws, int i, vector<int>& dp) {
        if(i == s.size()) {
            return 1;
        }
        if(dp[i] != -1) return dp[i];
        string tmp="";
        for(int j=i; j<s.size(); j++) {
            tmp += s[j];
            if(ws.find(tmp) != ws.end()) {
                if(solve(s, ws, j+1, dp)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> ws;
        vector<int> dp(s.size()+1, -1);
        for(string& word: wordDict) ws.insert(word);
        return solve(s, ws, 0, dp);
    }
};
