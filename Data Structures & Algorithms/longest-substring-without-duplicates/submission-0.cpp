class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ch[256]={0};
        int l=0, n=s.size();
        int ans=0;
        for(int r=0;r<n; r++) {
            ch[s[r]]++;
            while(ch[s[r]]>1) {
                ch[s[l]]--;
                l++;
            }
            ans= max(ans, r-l+1);
        }
        return ans;
    }
};
