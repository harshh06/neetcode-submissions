class Solution {
public:

    void solve(vector<vector<int>>& ans, vector<int>& cur, vector<int>& nums, int i) {
        if(i == nums.size()) {
            ans.push_back(cur);
            return ;
        }
        cur.push_back(nums[i]);
        solve(ans, cur, nums, i+1);
        cur.pop_back();
        solve(ans, cur, nums, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        solve(ans, cur, nums, 0);
        return ans;
    }
};
