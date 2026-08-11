class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++){
            int m=i, cnt=0;
            while(m) m=m&(m-1), cnt++;
            ans.push_back(cnt);
        }
        return ans;
    }
};
