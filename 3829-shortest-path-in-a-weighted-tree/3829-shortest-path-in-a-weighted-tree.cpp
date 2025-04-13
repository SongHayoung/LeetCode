class Solution {
    vector<vector<pair<int,int>>> adj;
    vector<pair<int,int>> par;
    vector<int> dep;
    int leaf = 0;
    void dfs(int u, int p, int d = 1) {
        bool lef = true;
        dep[u] = d;
        for(auto& [v,e] : adj[u]) {
            if(v == p) continue;
            par[v] = {u,e};
            dfs(v,u, d + 1);
            lef = false;
        }
        if(lef) leaf++;
    }
    vector<int> specialCase(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<int> at(n + 1), fenwick(n+2), res;
        for(int i = 1; i <= n; i++) at[i] = dep[i];
        auto udt = [&](int n, int x) {
            while(n < fenwick.size()) {
                fenwick[n] += x;
                n += n & -n;
            }
        };
        auto qry = [&](int n) {
            int res = 0;
            while(n) {
                res += fenwick[n];
                n -= n & -n;
            }
            return res;
        };
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            udt(max(dep[u], dep[v]), w);
        }
        for(auto& q : queries) {
            int op = q[0];
            if(op == 1) {
                int u = q[1], v = q[2], w = q[3], ch = par[u].first == v ? u : v, e = par[ch].second;
                udt(max(dep[u], dep[v]), -edges[e][2]);
                edges[e][2] = w;
                udt(max(dep[u], dep[v]), edges[e][2]);
            } else {
                res.push_back(qry(dep[q[1]]));
            }
        }
        return res;
    }
public:
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        adj = vector<vector<pair<int,int>>>(n+1);
        par = vector<pair<int,int>>(n+1);
        dep = vector<int>(n + 1);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back({v,i});
            adj[v].push_back({u,i});
        }
        par[1] = {-1,-1};
        dfs(1,-1);
        if(leaf == 1) {
            return specialCase(n,edges,queries);
        }
        vector<int> res;
        for(auto& q : queries) {
            int op = q[0];
            if(op == 1) {
                int u = q[1], v = q[2], w = q[3], ch = par[u].first == v ? u : v, e = par[ch].second;
                edges[e][2] = w;
            } else {
                int now = 0, u = q[1];
                while(u != 1) {
                    now += edges[par[u].second][2];
                    u = par[u].first;
                }
                res.push_back(now);
            }
        }
        return res;
    }
};