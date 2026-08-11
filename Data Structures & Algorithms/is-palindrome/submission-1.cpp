class Solution {
public:
    bool isValid (char ch) {
        return ((ch>='a'&& ch<='z') || (ch>='0'&&ch<='9') || (ch>='A'&&ch<='Z'));
    }
    bool isPalindrome(string s) {
        int l=0, r=s.size()-1;
        while(l<=r) {
            char chl=s[l], chr=s[r];
            if(!isValid(chl)) l++;
            else if(!isValid(chr)) r--;
            else {
                if(chl>='A'&&chl<='Z') chl=tolower(chl);
                if(chr>='A'&&chr<='Z') chr=tolower(chr);
                if(chl!=chr) return false;
                l++;
                r--;
            }
        }
        return true;
    }
};
