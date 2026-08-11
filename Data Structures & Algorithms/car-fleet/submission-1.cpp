class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double>st;
        vector<pair<int,int>> v;
        for(int i=0; i< position.size(); i++) v.push_back({position[i], speed[i]});
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++) {
            auto [pos, speed] = v[i];
            double time = double(target-pos)/speed;
            while(!st.empty() && st.top()<= time) st.pop();
            st.push(time);
        }
        return st.size();
    }
};
