class Solution {
    using t=pair<int,int>;
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int>dis(n+1, INT_MAX);
        vector<bool>vis(n+1, false);
        priority_queue<t, vector<t>, greater<t>>pq;
        int ans=0;
        dis[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto[d,u]=pq.top(); 
            pq.pop();
            if(vis[u]) continue;
            vis[u]=true;
            ans+=d;
            for(int v=0;v<n;v++) {
                if(vis[v]) continue;
                int cost=abs(points[v][0]-points[u][0])+
                        abs(points[v][1]-points[u][1]);
                if(cost<dis[v]) {
                    dis[v]=cost;
                    pq.push({cost, v});
                }
            }
        }
        return ans;
    }
};
