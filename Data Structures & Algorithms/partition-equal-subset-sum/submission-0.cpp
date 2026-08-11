class Solution {
public:

    bool solve(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {
        if(target==0) return true;
        if(i >= nums.size() || target < 0) return false;
        if(dp[i][target] != -1) return dp[i][target];
        return dp[i][target] = solve(nums, target-nums[i], i+1, dp) || solve(nums, target, i+1, dp);
    }
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(int& num: nums) total+=num;
        if(total%2) return false;
        vector<vector<int>> dp(nums.size()+1, vector<int> (total/2+1, -1));
        return solve(nums, total/2, 0, dp);
    }
};
