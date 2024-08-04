class Solution {
    vector<int> dp, res;
    vector<vector<int>> adj;
    int dfs1(int u, int par) {
        int& res = dp[u] = 0;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            int cost = v % 2 == 0 ? 2 : 1;
            res = max(res, cost + dfs1(v,u));
        }
        return res;
    }
    void dfs2(int u, int par, int pc) {
        vector<pair<int,int>> S{{pc,par},{0,u}};
        for(auto& v : adj[u]) {
            if(v == par) continue;
            int cost = v % 2 == 0 ? 2 : 1;
            S.push_back({dp[v] + cost, v});
            sort(rbegin(S), rend(S));
            S.pop_back();
        }
        auto get = [&](int v) {
            for(auto& [cost, ver] : S) {
                if(ver != v) return cost;
            }
            return 0;
        };
        for(auto& v : adj[u]) {
            if(v == par) continue;
            int cost = (u % 2 == 0 ? 2 : 1) + get(v);
            res[v] = max(res[v], cost);
            dfs2(v,u,cost);
        }
    }
public:
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        dp = vector<int>(n);
        adj = vector<vector<int>>(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs1(0,-1);
        res = dp;
        dfs2(0,-1,0);
        return res;
    }
};

