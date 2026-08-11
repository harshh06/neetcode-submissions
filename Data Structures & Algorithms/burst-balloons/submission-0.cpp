class Solution {
public:
    int solve(vector<int>&nums, int i, int j, vector<vector<int>>&dp) {
        if(i<0||j>=nums.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mx=0;
        int st = i-1<0?1:nums[i-1];
        int end = j+1>=nums.size()?1:nums[j+1];
        for(int k=i;k<=j;k++) {
            mx=max(mx, st*nums[k]*end + solve(nums,i,k-1,dp) + solve(nums,k+1,j,dp));
        }
        return dp[i][j] = mx;
    }
    int maxCoins(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+1,-1));
        return solve(nums,0,nums.size()-1,dp);
    }
};
