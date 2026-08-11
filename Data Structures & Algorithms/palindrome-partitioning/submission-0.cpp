class Solution {
public:

    bool isPal(string s) {
        int l=0, r=s.size()-1;
        while(l<r && s[l] == s[r]) l++, r--;
        return l>=r;
    }

    void solve(vector<vector<string>>& ans, vector<string>& cur, string& s, int i) {
        if(i == s.size()){
            ans.push_back(cur);
            return;
        }
        for(int k=i; k< s.size(); k++) {
            string tmp = s.substr(i, k-i+1);
            if(isPal(tmp)) {
                cur.push_back(tmp);
                solve(ans, cur, s, k+1);
                cur.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        solve(ans, cur, s, 0);
        return ans;
    }
};
