class Solution {
public:
    int trap(vector<int>& height) {
        int water=0;
        int ml=0, mr=0;
        int l=0,r=height.size()-1;
        while(l<r){
            if(height[l]<=height[r]){
                ml=max(ml, height[l]);
                water+= ml-height[l];
                l++;
            } else{
                mr = max(mr, height[r]);
                water += mr-height[r];
                r--;
            }
        }
        return water;
    }
};
