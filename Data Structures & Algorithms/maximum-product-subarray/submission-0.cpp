class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0], mx=nums[0], mn=nums[0];
        for(int i=1; i<nums.size(); i++){
            int tmp=mx;
            mx=max({nums[i], mx*nums[i], mn*nums[i]});
            mn=min({nums[i], tmp*nums[i], mn*nums[i]});
            ans=max(ans, mx);
        }
        return ans;
    }
};
