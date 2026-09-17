class Solution {
public:

    using pii = pair<int, int>;

    void dijkstra(vector<vector<pii>>& adj, vector<int>& d, vector<int>& p, int s, int n) {
        d.assign(n+1, INT_MAX);
        p.assign(n+1, -1);
        d[s] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        q.push({0, s});
        while(!q.empty()) {
            int v = q.top().second;
            int d_v = q.top().first;
            q.pop();
            if(d_v != d[v]) continue;
            for(auto edge: adj[v]) {
                int to = edge.first;
                int len = edge.second;
                if(d[to] > d[v] + len) {
                    d[to] = d[v] + len;
                    p[to] = v;
                    q.push({d[to], to});
                }
            }
        }
    }


    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pii>> adj(n+1);
        for(int i=0; i< times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int> d, p;
        dijkstra(adj, d, p, k, n);
        int ans = *max_element(d.begin()+1, d.end());
        return ans == INT_MAX ? -1: ans;
    }
};
