class Solution {
    vector<int> adj[55];
    vector<int> p;
    vector<int> freq;
    void dfs(int u, int par, int goal, vector<int>& path) {
        path.push_back(u);
        if(u == goal) return;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            dfs(v,u,goal,path);
            if(path.back() == goal) return;
        }
        path.pop_back();
    }
    void mark(int u, int v) {
        vector<int> path;
        dfs(u,-1,v,path);
        for(auto p : path) freq[p] += 1;
    }
    pair<long long, long long> helper(int u, int par) {
        long long self = 0, child = 0;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            auto [cs, cc] = helper(v,u);
            self += cc, child += cs;
        }
        self += p[u] / 2 * freq[u];
        self = max(self, child);
        return {self, child};
    }
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        freq = vector<int>(n);
        p = price;
        for(int i = 0; i < n; i++) adj[i].clear();
        for(auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(auto t : trips) mark(t[0],t[1]);
        auto [a,b] = helper(0,-1);
        long long res = 0;
        for(int i = 0; i < n; i++) {
            res += freq[i] * p[i];
        }
        res -= max(a,b);
        return res;
    }
};
