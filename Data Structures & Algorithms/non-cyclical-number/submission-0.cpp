class Solution {
public:
    int cal(int n) {
        int sum=0;
        while(n>0) {
            int m=n%10;
            sum+=m*m;
            n/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        bool repeat=false;
        unordered_map<int, bool>mp;
        while(true) {
            int sum=cal(n);
            if(sum==1) return true;
            if(mp.contains(sum)) return false;
            mp[sum]=true;
            n=sum;
        }
        return false;
    }
};
