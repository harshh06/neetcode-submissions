class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& cur, vector<int>& nums, int i) {
        if(i == nums.size()) {
            ans.push_back(cur);
            return;
        }
        if(i >= nums.size()) return;
        cur.push_back(nums[i]);
        solve(ans, cur, nums, i+1);
        while(i < nums.size() - 1 && nums[i] == nums[i+1]) i++;
        cur.pop_back();
        solve(ans, cur, nums, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        solve(ans, cur, nums, 0);
        return ans;
    }
};
