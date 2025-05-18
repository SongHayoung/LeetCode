int level[101010], LCA[101010][22], dis[101010];
vector<pair<int,int>> adj[101010];
void dfs(int u, int lvl, int d, int par) {
    level[u] = lvl;
    dis[u] = d;
    LCA[u][0] = par;
    for(int i = 1; i < 22; i++) {
        LCA[u][i] = LCA[LCA[u][i-1]][i-1];
    }
    for(auto& [v, w] : adj[u]) {
        if(v == par) continue;
        dfs(v, lvl + 1, d + w, u);
    }
}
int query(int u, int v) {
    if(level[u] < level[v]) swap(u, v);
    int diff = level[u] - level[v];
    for(int i = 0; diff; i++, diff /= 2) {
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
int distance(int u, int v) {
    int lca = query(u,v);
    return dis[u] + dis[v] - 2 * dis[lca];
}
int median(int a, int b, int c) {
    int x = query(a,b), y = query(a,c), z = query(b,c);
    int res = x;
    if(level[y] > level[res]) res = y;
    if(level[z] > level[res]) res = z;
    return res;
}
int distance(int a, int b, int c) {
    int best = median(a,b,c);
    return distance(best,a) + distance(best,b) + distance(best,c);
}
class Solution {
public:
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        for(int i = 0; i < n; i++) adj[i+1].clear();
        for(auto& e : edges) {
            int u = e[0] + 1, v = e[1] + 1, w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dfs(1,0,0,0);
        vector<int> res;
        for(auto& q : queries) {
            res.push_back(distance(q[0] + 1, q[1] + 1, q[2] + 1));
        }
        return res;
    }
};
