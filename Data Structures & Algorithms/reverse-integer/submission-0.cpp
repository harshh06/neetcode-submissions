class Solution {
public:
    int reverse(int x) {
        int y=0;
        while(x){
            if(y>INT_MAX/10) return 0;
            if(y<INT_MIN/10) return 0;
            int lastDigit=x%10;
            x=x/10;
            y=(y*10)+lastDigit;
        }
        return y;
    }
};
