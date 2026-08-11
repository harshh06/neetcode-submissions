class Solution {
    using t=pair<int, int>;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int>dis(n+1, INT_MAX);
        priority_queue<t, vector<t>, greater<t>> pq;
        for(int i=0; i< times.size(); i++) {
            int u=times[i][0], v=times[i][1], t=times[i][2];
            adj[u].push_back({v,t});
        }
        dis[k]=0;
        pq.push({dis[k], k});
        while(!pq.empty()){
            auto [d, u] = pq.top(); pq.pop();
            if(d>dis[u]) continue;
            for(auto [v, w]: adj[u]) {
                if(dis[u]+w < dis[v]) {
                    dis[v]=dis[u]+w;
                    pq.push({dis[v], v});
                }
            }
        }
        int ans = *max_element(dis.begin()+1, dis.end());
        return ans == INT_MAX ? -1 : ans;
    }
};
