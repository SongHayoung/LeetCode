bool dp[1<<14][14][14];
class Solution {
    bool on(int bit, int fl) {
        return ((bit>>fl)&1);
    }
public:
    int maxLen(int n, vector<vector<int>>& edges, string label) {
        memset(dp,0,sizeof dp);
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            if(label[u] == label[v]) dp[(1<<u) | (1<<v)][min(u,v)][max(u,v)] = 1;
        }
        for(int i = 0; i < n; i++) dp[1<<i][i][i] = 1;
        int res = 0;
        for(int mask = 0; mask < 1<<n; mask++) {
            for(int u = 0; u < n; u++) {
                for(int v = 0; v < n; v++) {
                    if(!dp[mask][u][v]) continue;
                    res = max(res, __builtin_popcount(mask));
                    for(auto& uu : adj[u]) {
                        if(on(mask,uu)) continue;
                        for(auto& vv : adj[v]) {
                            if(on(mask,vv)) continue;
                            if(uu == vv) continue;
                            if(label[uu] != label[vv]) continue;
                            dp[mask | (1<<uu) | (1<<vv)][min(uu,vv)][max(uu,vv)] = 1;
                        }
                    }
                }
            }
        }
        return res;
    }
};