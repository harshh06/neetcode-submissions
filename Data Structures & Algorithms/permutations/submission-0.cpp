class Solution {
public:

    void solve(vector<vector<int>>& ans, vector<int>& cur, vector<int>& nums, vector<bool>& used) {
        if(cur.size() == nums.size()) {
            ans.push_back(cur);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(used[i]) continue;
            cur.push_back(nums[i]);
            used[i] = true;
            solve(ans, cur, nums, used);
            cur.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        solve(ans, cur, nums, used);
        return ans;
    }
};
