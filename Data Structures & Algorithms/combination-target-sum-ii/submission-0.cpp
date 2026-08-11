class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& cur, vector<int>& candidates, int target, int i) {
        if(target == 0) {
            ans.push_back(cur);
            return;
        }
        if(target < 0 || i >= candidates.size()) return;

        cur.push_back(candidates[i]);
        solve(ans, cur, candidates, target - candidates[i], i+1);
        cur.pop_back();
        while(i < candidates.size() - 1 && candidates[i] == candidates[i+1]) i++;
        solve(ans, cur, candidates, target , i+1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        solve(ans, cur, candidates, target, 0);
        return ans;
    }
};
