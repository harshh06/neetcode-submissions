class Solution {
public:
    bool isValid(char ch) {
        return (ch>='a' && ch<='z') || (ch>='A'&&ch<='Z') || (ch>='0'&&ch<='9');
    }
    bool isPalindrome(string s) {
        int l=0, r=s.size()-1;
        while(l<r){
            if(!isValid(s[l])) l++;
            else if (!isValid(s[r])) r--;
            else if(tolower(s[l])!= tolower(s[r])) return false;
            else {
                l++;r--;
            }
        }
        return true;
    }
};
