class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map< string, priority_queue<string, vector<string>, greater<string>> > adj;
        for(auto& t: tickets) {
            adj[t[0]].push(t[1]);
        }
        stack<string> st;
        vector<string> order;
        st.push("JFK");
        while(!st.empty()) {
            string node = st.top();
            if(adj[node].empty()) {
                order.push_back(node);
                st.pop();
            } else {
                string next = adj[node].top();
                adj[node].pop();
                st.push(next);
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};
