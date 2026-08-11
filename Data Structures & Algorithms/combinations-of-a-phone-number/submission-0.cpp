class Solution {
public:

    void solve(vector<string>& ans, string& cur, string& digits, unordered_map<char, string>& mp, int i) {
        if(i == digits.size()) {
            ans.push_back(cur);
        }
        for(char& ch: mp[digits[i]]) {
            cur.push_back(ch);
            solve(ans, cur, digits, mp, i+1);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {};
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> ans;
        string cur;
        solve(ans, cur, digits, mp, 0);
        return ans;
    }
};
