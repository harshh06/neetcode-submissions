class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>need, window;
        for(char ch: t) need[ch]++;
        int req=need.size();
        int match=0;
        int l=0, ans = INT_MAX, r=0, st=0;
        for(r=0;r< s.size(); r++) {
            window[s[r]]++;
            if(need[s[r]] == window[s[r]]) match++;
            while(match == req) {
                if(r-l+1<ans) {
                    ans = min(ans, r-l+1);
                    st=l;
                }
                window[s[l]]--;
                if(need[s[l]]>0 && window[s[l]]<need[s[l]]) match--;
                l++;
            }
        }
        return ans==INT_MAX? "": s.substr(st,ans);
    }
};
