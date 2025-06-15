
const int MAX_N = 101010;
vector<pair<int,int>> adj[MAX_N];
long long level[MAX_N], LCA[MAX_N][22], dep[MAX_N];
void dfs(long long u, long long lvl, long long par) {
    level[u] = lvl;
    LCA[u][0] = par;
    for(int i = 1; i < 22; i++) {
        LCA[u][i] = LCA[LCA[u][i-1]][i-1];
    }
    for(auto& [v,w] : adj[u]) {
        if(v == par) continue;
        dep[v] = dep[u] + w;
        dfs(v, lvl + 1, u);
    }
}
long long lcaQuery(long long u, long long v) {
    if(level[u] < level[v]) swap(u, v);
    long long diff = level[u] - level[v];
    for(long long i = 0; diff; i++, diff /= 2) {
        if(diff & 1) u = LCA[u][i];
    }
    if(u != v) {
        for(int i = 21; i >= 0; i--) {
            if(LCA[u][i] == LCA[v][i]) continue;
            u = LCA[u][i];
            v = LCA[v][i];
        }
        u = LCA[u][0];
    }
    return u;
}
long long distance(long long u, long long v) {
    long long lca = lcaQuery(u,v);
    return dep[u] + dep[v] - 2 * dep[lca];
}
long long helper(int u, long double d, bool fl) {
    while(1) {
        int v = -1;
        for(int i = 21; i >= 0; i--) {
            if(LCA[u][i] == 0) continue;
            if(dep[u] - dep[LCA[u][i]] < d) {
                v = LCA[u][i];
                break;
            }
        }
        if(v == -1) break;
        d = d - dep[u] + dep[v];
        u = v;
    }
    if(fl) return u - 1;
    return LCA[u][0] - 1;
}
class Solution {
public:
    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        memset(LCA,0,sizeof LCA);
        for(int i = 1; i <= n; i++) adj[i].clear();
        for(auto& e : edges) {
            int u = e[0] + 1, v = e[1] + 1, w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dfs(1,0,0);
        vector<int> res;
        for(auto& q : queries) {
            int u = q[0] + 1, v = q[1] + 1;
            int lca = lcaQuery(u,v);
            long double d = distance(u,v);
            if(u == v) {
                res.push_back(u - 1);
            } else if(lca == v) {
                res.push_back(helper(u,d / 2., false));
            } else if(lca == u) {
                res.push_back(helper(v, d / 2. + 0.1, true));
            } else {
                long double du = distance(u,lca);
                if(du * 2 < d) {
                    long double rem = dep[v] - dep[lca] - (d / 2. - du);
                    res.push_back(helper(v, rem + 0.1, true));
                } else res.push_back(helper(u, d/2., false));
            }
        }

        return res;
    }
};