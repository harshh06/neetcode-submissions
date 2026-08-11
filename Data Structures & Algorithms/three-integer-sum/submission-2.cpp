class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int k=0;k<nums.size()-2;k++) {
            if(k>0 && nums[k]==nums[k-1]) continue;
            int l=k+1, r=nums.size()-1;
            while(l<r) {
                int sum=nums[k]+nums[l]+nums[r];
                if(sum==0) {
                    ans.push_back({nums[k],nums[l],nums[r]});
                    l++; r--;
                    while(l<nums.size() && nums[l]==nums[l-1]) l++;
                    while(r>=0 && nums[r]==nums[r+1]) r--;
                }
                else if(sum<0) l++;
                else r--;
            }
        }
        return ans;
    }
};
