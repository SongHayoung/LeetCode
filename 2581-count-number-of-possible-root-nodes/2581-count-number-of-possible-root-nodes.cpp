class Solution {
    unordered_map<int, unordered_map<int, int>> dp;
    unordered_map<int, unordered_set<int>> q;
    vector<int> adj[101010];
    int dfs(int u, int par) {
        if(dp[u].count(par)) return dp[u][par];
        int& res = dp[u][par] = 0;
        if(q.count(u) and q[u].count(par)) res += 1;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            res += dfs(v,u);
        }
        return res;
    }
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        for(auto g : guesses) {
            q[g[1]].insert(g[0]);
        }
        int n = edges.size() + 1;
        for(auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            int now = dfs(i,-1);
            if(now >= k) res += 1;
        }
        return res;
    }
};