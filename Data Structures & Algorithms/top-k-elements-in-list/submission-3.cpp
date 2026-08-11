class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int num: nums) mp[num]++;
        using t = pair<int, int>;
        priority_queue<t, vector<t>, greater<t>> pq;
        for(auto x: mp) {
            pq.push({x.second, x.first});
            if(pq.size()> k) pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second); pq.pop();
        }
        return ans;
    }
};
