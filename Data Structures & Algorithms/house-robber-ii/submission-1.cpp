class Solution {
public:
    int solve(int n, vector<int>& nums, vector<int>& dp) {
        if(n==0) return nums[0];
        if(n==1) return max(nums[0], nums[1]);
        if(dp[n]!=-1) return dp[n];
        return dp[n] = max(solve(n-1, nums, dp), solve(n-2, nums, dp) + nums[n]);
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> n1(nums.begin(), nums.end()-1);
        vector<int> n2(nums.begin()+1, nums.end());
        vector<int> dp(nums.size(), -1);
        int n = n1.size();
        int firstSol = solve(n-1, n1, dp);
        dp.assign(dp.size(),-1);
        n=n2.size();
        int secSol = solve(n-1, n2, dp);
        return max(firstSol, secSol);
    }
};
