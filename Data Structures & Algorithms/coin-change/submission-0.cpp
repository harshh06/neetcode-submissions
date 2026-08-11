class Solution {
public:
    int solve(vector<int>& coins, int amount, int cnt, int i, vector<vector<int>>& dp) {
        if(amount < 0 || i>= coins.size()) return INT_MAX;
        if(amount==0) {
            // ans=min(ans, cnt);
            return 0;
        }
        int use = solve(coins, amount-coins[i], cnt+1, i, dp);
        int skip = solve(coins, amount, cnt, i+1, dp);
        if(use != INT_MAX) use += 1;
        return dp[i][amount] = min(use, skip); 
    }

    int coinChange(vector<int>& coins, int amount) {
        int cnt=0;
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans = solve(coins, amount, cnt, 0, dp);
        return ans==INT_MAX?-1:ans;
    }
};
