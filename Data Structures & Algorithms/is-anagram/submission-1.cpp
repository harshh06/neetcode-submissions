class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int cnt[27]={0};
        for(char ch:s) cnt[ch-'a']++;
        for(char ch: t) {
            cnt[ch-'a']--;
            if(cnt[ch-'a']<0) return false;
        }
        return true;
    }
};
