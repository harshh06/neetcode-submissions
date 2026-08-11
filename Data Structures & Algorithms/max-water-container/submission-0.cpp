class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int l=0, r=n-1;
        int ans=0;

        while(l<r){
            int hl=heights[l], hr=heights[r];
            int area = (r-l)*min(hl, hr);
            ans=max(ans, area);
            if(hl<hr) l++;
            else r--;
        }
        return ans;
    }
};
