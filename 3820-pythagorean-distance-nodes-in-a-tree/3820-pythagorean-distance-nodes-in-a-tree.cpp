
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
class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        memset(LCA,0,sizeof LCA);
        for(int i = 1; i <= n; i++) adj[i].clear();
        for(auto& e : edges) {
            int u = e[0] + 1, v = e[1] + 1, w = 1;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        x += 1, y += 1, z += 1;
        dfs(1,0,0);
        int res = 0;
        for(int i = 1; i <= n; i++) {
            long long dx = distance(i,x), dy = distance(i,y), dz = distance(i,z);
            vector<long long> d{dx,dy,dz};
            sort(begin(d), end(d));
            if(d[0] * d[0] + d[1] * d[1] == d[2] * d[2]) res++;
        }
        return res;
    }
};
