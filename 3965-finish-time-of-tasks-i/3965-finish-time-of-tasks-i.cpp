class Solution {
    long long dfs(vector<vector<int>>& adj, int u, int par, vector<int>& A) {
        long long mi = LLONG_MAX, ma = LLONG_MIN;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            long long sub = dfs(adj,v,u,A);
            mi = min(mi, sub);
            ma = max(ma, sub);
        }
        if(mi == LLONG_MAX) return A[u];
        return A[u] + (ma - mi) + ma;
    }
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(adj,0,-1,baseTime);
    }
};