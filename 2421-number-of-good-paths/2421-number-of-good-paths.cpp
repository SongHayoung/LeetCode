class Solution {
    vector<int> uf;
    unordered_map<int, int> level;
    unordered_map<int, int> par;
    unordered_map<int, vector<int>> adj;
    void dfs(int u, int p, int lvl = 0) {
        par[u] = p;
        level[u] = lvl;
        for(auto v : adj[u]) {
            if(v == p) continue;
            dfs(v,u, lvl + 1);
        }
    }
    int find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        uf[pu] = uf[pv] = level[pu] < level[pv] ? pu : pv;
    }
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        for(auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1);
        vector<pair<int, int>> A;
        for(int i = 0; i < vals.size(); i++) A.push_back({vals[i],i});
        uf = vector<int>(vals.size());
        iota(begin(uf), end(uf),0);
        int res = vals.size();
        sort(begin(A), end(A));
        int l = 0, r = 0, n = A.size();
        while(r < n) {
            while(r < n and A[l].first == A[r].first) r++;
            unordered_map<int, int> now;
            while(l < r) {
                auto [_, u] = A[l];
                u = find(u);
                while(par[u] != -1 and vals[par[u]] <= A[l].first) {
                    uni(u,par[u]);
                    u = find(u);
                }
                res += now[u];
                now[u] += 1;
                l += 1;
            }
        }
        return res;
    }
};