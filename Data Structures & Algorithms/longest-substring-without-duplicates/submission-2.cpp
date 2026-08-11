class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ch[256]={0}, l=0;
        int ans=0;
        for(int r=0; r< s.size(); r++) {
            ch[s[r]]++;
            while(l<r && ch[s[r]]>1) {
                ch[s[l]]--;
                l++;
            } 
            ans=max(ans, r-l+1);
        }
        return ans;
    }
};
