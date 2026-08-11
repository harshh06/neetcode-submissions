class Solution {
public:
    int solve(vector<int>& prices, int i, bool holding, vector<vector<int>>& dp) {
        if(i>=prices.size()) return 0;
        if(dp[i][holding] != -1) return dp[i][holding];
        if(holding) {
            return dp[i][holding] = max(
                solve(prices, i+1, true, dp),
                solve(prices, i+2, false, dp) + prices[i]
            );
        } return dp[i][holding] = max(
            solve(prices, i+1, false, dp),
            solve(prices, i+1, true, dp) - prices[i]
        );
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, false, dp);
    }
};
