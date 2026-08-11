class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<k;i++) pq.push({nums[i], i});
        vector<int> ans;
        ans.push_back(pq.top().first);
        for(int r=k;r<nums.size(); r++) {
            pq.push({nums[r], r});
            while(!pq.empty() && pq.top().second < r-k+1) pq.pop();
            if(!pq.empty()) ans.push_back(pq.top().first);
        }
        return ans;
    }
};
