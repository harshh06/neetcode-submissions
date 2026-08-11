class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        unordered_map<int , vector<int>> mp;
        vector<int> vis(n, 0);
        for(int i=0; i< n-1; i++) {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        q.push(0);
        int cnt = 1;
        while(!q.empty()) {
            int v = q.front();
            vis[v] = 1;
            q.pop();
            for(int &u: mp[v]) {
                if(!vis[u]) {
                    cnt ++;
                    q.push(u);
                }
            }
        }
        if(cnt != n) return false;
        return true;
    }
};
