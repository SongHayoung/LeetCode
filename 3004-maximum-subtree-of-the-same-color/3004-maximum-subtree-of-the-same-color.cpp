class Solution {
    pair<int,int> dfs(vector<vector<int>>& adj, vector<int>& c, int u, int par, int& res) {
        int sub = 1;
        bool ok = true;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            auto [cc,cnt] = dfs(adj,c,v,u,res);
            if(cc != c[u]) ok = false;
            sub += cnt;
        }
        if(!ok) return {-1,sub};
        res = max(res, sub);
        return {c[u],sub};
    }
public:
    int maximumSubtreeSize(vector<vector<int>>& edges, vector<int>& colors) {
        vector<vector<int>> adj(edges.size() + 1);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int res = 1;
        dfs(adj, colors, 0, -1, res);
        return res;
    }
};
