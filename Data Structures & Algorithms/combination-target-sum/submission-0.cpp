class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& cur, vector<int>& nums, int target, int i) {
        if(target == 0) {
            ans.push_back(cur);
            return;
        }
        if(target <0 || i >= nums.size()) return;
        cur.push_back(nums[i]);
        solve(ans, cur, nums, target - nums[i], i);
        cur.pop_back();
        solve(ans, cur, nums, target, i+1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        solve(ans, cur, nums, target, 0);
        return ans;
    }
};
