class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        int need[26]={0}, window[26]={0};
        for(char ch: s1) need[ch-'a']++;
        int k=s1.size(), l=0;
        for(int i=0;i<k;i++) window[s2[i]-'a']++;
        if(equal(window, window+26, need)) return true;
        for(int i=k;i<s2.size(); i++) {
            window[s2[i]-'a']++;
            window[s2[i-k]-'a']--;
            if(equal(window, window+26, need)) return true;
        }
        return false;
    }
};
