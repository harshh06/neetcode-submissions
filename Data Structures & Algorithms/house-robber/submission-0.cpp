class Solution {
public:
    int solve(int n, vector<int>& nums, vector<int>& dp) {
        if(n==0) return nums[0];
        if(n==1) return max(nums[0], nums[1]);
        if(dp[n]!=-1) return dp[n];
        return dp[n] = max(solve(n-1, nums, dp), solve(n-2, nums, dp) + nums[n]);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n - 1, nums, dp);
    }
};
