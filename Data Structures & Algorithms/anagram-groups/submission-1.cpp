class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(string str: strs){
            string tmp="";
            int cnt[26]={0};
            for(char ch: str) {
                cnt[ch-'a']++;
            }
            for(int i=0; i<26;i++) {
                tmp.push_back(cnt[i]);
            }
            mp[tmp].push_back(str);
        }
        vector<vector<string>> anagrams;
        for(auto x: mp) {
            vector<string> tmp;
            for(string s: x.second) {
                tmp.push_back(s);
            }
            anagrams.push_back(tmp);
        }
        return anagrams;
    }
};
