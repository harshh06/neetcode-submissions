class Solution {
public:
    int solve(int amount, vector<int>& coins, int i, vector<vector<int>>& dp) {
        if(amount < 0 || i>=coins.size()) return 0;
        if(amount == 0) return 1;
        if(dp[i][amount] != -1) return dp[i][amount];
        return dp[i][amount] = solve(amount, coins, i+1, dp) + solve(amount-coins[i], coins, i, dp);
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
        return solve(amount, coins, 0, dp);
    }
};
