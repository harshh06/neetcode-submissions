class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        bool isNeg=n<0;
        n=abs(n);
        double ans=1;
        while(n-->0) ans=ans*x;
        if(isNeg) ans=1/ans;
        return ans;
    }
};
