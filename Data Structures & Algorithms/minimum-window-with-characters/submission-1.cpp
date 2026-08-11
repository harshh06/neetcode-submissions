class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for(char ch: t) need[ch]++;
        int req=need.size();
        int have=0;
        int minLen=INT_MAX, l=0, start=0;
        for(int r=0;r<s.size();r++) {
            window[s[r]]++;
            if(need.count(s[r]) && need[s[r]]== window[s[r]]) have++;
            while(have == req) {
                // update the ans
                if(minLen > r-l+1) {
                    minLen = r-l+1;
                    start = l;
                }
                window[s[l]]--;
                if(need.count(s[l]) && need[s[l]] > window[s[l]]) have--;
                l++;
            }
        }
        return minLen==INT_MAX ? "" : s.substr(start, minLen);
    }
};
