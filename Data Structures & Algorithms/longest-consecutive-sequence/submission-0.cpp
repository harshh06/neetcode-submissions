class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans=0;
        unordered_set<int> us(nums.begin(), nums.end());
        for(int num: nums){
            if(us.find(num-1)!=us.end()) continue;
            int x=num, cnt=1;
            while(us.find(x+1)!=us.end()) {
                x=x+1;cnt++;
            }
            ans=max(ans, cnt);
        }
        return ans;
    }
};
