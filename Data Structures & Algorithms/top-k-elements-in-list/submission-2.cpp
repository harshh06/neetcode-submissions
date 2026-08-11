class Solution {
public:
    using t=pair<int,int>;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(int num: nums) mp[num]++;
        priority_queue<t, vector<t>, greater<t>>pq;
        for(auto x: mp) {
            if(pq.size()<k) pq.push({x.second, x.first});
            else if(pq.top().first < x.second) {
                pq.pop();
                pq.push({x.second, x.first});
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
