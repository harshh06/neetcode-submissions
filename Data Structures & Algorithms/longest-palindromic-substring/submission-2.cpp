class Solution {
public:
    string longestPalindrome(string s) {
        int len=0, ml=-1, mr=-1, n=s.size();
        for(int i=0; i<n; i++) {
            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r]) {
                int curLen=r-l+1;
                if(curLen>len) {
                    len=curLen;
                    ml=l; mr=r;
                }
                l--; r++;
            }
            l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]) {
                int curLen=r-l+1;
                if(curLen>len) {
                    len=curLen;
                    ml=l; mr=r;
                }
                l--; r++;
            }
        }
        cout << ml << " " << mr ;
        return s.substr(ml, mr-ml+1);
    }
};
