class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float>st;
        int n = speed.size();
        vector<pair<int,int>> info;
        for(int i=0; i<n; i++) {
            info.push_back({position[i], speed[i]});
        }
        sort(info.begin(), info.end());
        for(int i=0; i<n;i++) {
            float t = float(target-info[i].first) / float(info[i].second);
            while(!st.empty() && st.top()<=t) st.pop();
            st.push(t);
        }
        return st.size();
    }
};
