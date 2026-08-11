class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int>cnt;
        for(int num: nums) if(!cnt.contains(num)) cnt[num]++;
        int ans=0;
        for(auto& x:cnt) {
            if(cnt.contains(x.first-1)) {
                x.second = x.second + cnt[x.first-1];
            } 
            ans=max(x.second, ans);
        }
        return ans;
    }
};
