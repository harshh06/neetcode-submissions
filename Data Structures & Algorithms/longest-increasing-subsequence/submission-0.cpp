class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp) {
        if(dp[i]!=-1) return dp[i];
        int best=1;
        for(int j=i+1; j<nums.size(); j++) {
            if(nums[j]>nums[i]) {
                best=max(best, 1 + solve(nums, j, dp));
            } 
        }
        return dp[i] = best;
    }

    int lengthOfLIS(vector<int>& nums) {
        int ans=0;
        vector<int>dp(nums.size()+1, -1);
        for(int i=0; i<nums.size();i++) {
            dp[i] = solve(nums, i, dp);
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};
