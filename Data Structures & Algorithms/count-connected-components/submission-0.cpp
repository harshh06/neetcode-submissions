class Solution {
public:
    void dfs(int v, unordered_map<int, vector<int>>& mp, vector<int>& vis) {
        vis[v] = 1;
        for(int &u: mp[v]) {
            if(!vis[u]) dfs(u, mp, vis);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        int cnt = 0;
        vector<int> vis(n, 0);
        unordered_map<int, vector<int>> mp;
        for(auto &edge: edges) {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }   

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i, mp, vis);
                cnt++;
            }
        }

        return cnt;
    }
};
