class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0, i=digits.size()-1;
        digits[i]+=1;
        if(digits[i]==10) digits[i]=0, carry=1, i-=1;
        while(i>=0 && carry) {
            int sum=digits[i]+carry;
            digits[i]=sum%10;
            carry=sum/10;
            i-=1;
        }
        vector<int>ans;
        if(carry) ans.push_back(carry);
        for(int digit: digits) ans.push_back(digit);
        return ans;
    }
};
