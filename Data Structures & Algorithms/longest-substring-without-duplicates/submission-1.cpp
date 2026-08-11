class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        char ch[256]={0};
        int l=0, ans=0;
        for(int r=0;r<s.size(); r++) {
            ch[s[r]]++;
            while(l<r && ch[s[r]]>1) {
                ch[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
