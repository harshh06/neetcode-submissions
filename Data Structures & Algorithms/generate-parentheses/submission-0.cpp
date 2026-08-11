class Solution {
public:

    void solve(vector<string>& ans, string& cur, int n, int open, int close) {
        if(close > open || open > n || close > n) return;
        if(cur.size() == 2*n) {
            ans.push_back(cur);
            return;
        }
        if(open >= close) {
            cur += "(";
            solve(ans, cur, n, open+1, close);
            cur.pop_back();
            cur += ")";
            solve(ans, cur, n, open, close+1);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur = "";
        solve(ans, cur, n, 0, 0);
        return ans;   
    }
};
