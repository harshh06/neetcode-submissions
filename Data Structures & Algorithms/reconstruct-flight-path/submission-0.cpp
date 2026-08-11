class Solution {
public:
    void dfs(string v, vector<string>&path, unordered_map<string, multiset<string>>&adj) {
        while(!adj[v].empty()) {
            string u=*adj[v].begin();
            adj[v].erase(adj[v].begin());
            dfs(u,path,adj);
        }
        path.push_back(v);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adj;
        for(auto ticket: tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }
        vector<string>path;
        dfs("JFK", path, adj);
        reverse(path.begin(), path.end());
        return path;
    }
};
