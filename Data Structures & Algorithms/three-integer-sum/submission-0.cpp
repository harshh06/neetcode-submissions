class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>>us;
        for(int k=0; k<nums.size(); k++) {
            int l=k+1, r=nums.size()-1;
            while(l<r){
                int sum=nums[l]+nums[k]+nums[r];
                if(sum==0) us.insert({nums[l],nums[k],nums[r]});
                if(sum<0)l++;
                else r--;
            }
        }
        return vector<vector<int>>(us.begin(),us.end());
    }
};
