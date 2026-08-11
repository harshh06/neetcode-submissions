class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r=*max_element(piles.begin(), piles.end());
        while(l<r) {
            int mid = l+(r-l)/2;
            int totalHrs=0;
            for(int pile: piles) totalHrs += (pile+mid-1) / mid;
            if(totalHrs<=h) r=mid;
            else l=mid+1;
        }
        return l;
    }
};
