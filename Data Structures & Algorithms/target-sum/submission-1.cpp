class Solution {
public:
    int solve(vector<int>& nums, int target, int i, map<pair<int, int>, int>& dp) {
        if(target == 0 && i == nums.size()) return 1;
        if(i>=nums.size()) return 0;
        if(dp.contains({i, target})) return dp[{i, target}];
        return dp[{i, target}] = solve(nums, target-nums[i], i+1, dp) + solve(nums, target+nums[i], i+1, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> dp;
        return solve(nums, target, 0, dp);
    }
};
