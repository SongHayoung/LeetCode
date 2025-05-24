const int MAX_N = 101010;
const int mod = 1e9 + 7;
long long modpow(long long n, long long x, long long MOD = mod) {if(x<0){return modpow(modpow(n,-x,MOD),MOD-2,MOD);}n%=MOD;long long res=1;while(x){if(x&1){res=res*n%MOD;}n=n*n%MOD;x>>=1;}return res;}
vector<int> adj[MAX_N];
int level[MAX_N], LCA[MAX_N][22];
void dfs(long long u, long long lvl, long long par) {
    level[u] = lvl;
    LCA[u][0] = par;
    for(int i = 1; i < 22; i++) {
        LCA[u][i] = LCA[LCA[u][i-1]][i-1];
    }
    for(auto& v : adj[u]) {
        if(v == par) continue;
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
class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        long long n = edges.size() + 1;
        for(int i = n; i; i--) adj[i].clear();
        for(int i = 0; i < edges.size(); i++) {
            long long u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,0,0);
        vector<int> res;
        for(int i = 0; i < queries.size(); i++) {
            long long u = queries[i][0], v = queries[i][1];
            if(u == v) res.push_back(0);
            else {
                long long lca = lcaQuery(u,v);
                long long dis = level[u] - level[lca] + level[v] - level[lca];
                res.push_back(modpow(2,dis-1));
            }
        }
        return res;
    }
};