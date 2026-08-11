class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(string str: strs) {
            vector<int>cnt(27,0);
            for(char ch: str) cnt[ch-'a']++;
            string cntStr="";
            for(int x: cnt) cntStr+=(char)x;
            mp[cntStr].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto x: mp) {
            vector<string> tmp;
            for(string s: x.second) tmp.push_back(s);
            ans.push_back(tmp);  
        }
        return ans;
    }
};
