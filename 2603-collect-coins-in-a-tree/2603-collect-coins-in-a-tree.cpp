class Solution {
    vector<int> adj[30001];
    int c[30001], dp[30001], sub[30001], p[30001];
    int dfs1(int u, int par) {
        p[u] = par;
        dp[u] += c[u];
        sub[u] += c[u];
        for(auto& v : adj[u]) {
            sub[u] += c[v];
            if(v == par) continue;
            dp[u] += dfs1(v,u);
        }
        return dp[u];
    }
    int suball(int u, int par, int tot) {
        if(par == p[u]) return dp[u];
        return tot - (par >= 0 ? dp[par] : 0);
    }
    bool move(int u, int v, int tot) {
        if(u == -1 or v == -1) return 0;
        return suball(v,u,tot) > sub[v] - c[u];
    }
    int dfs0(int u, int par, int tot) {
        int res = 0;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            if(move(u,v,tot)) {
                res += 2 + dfs0(v,u,tot);
            }
        }
        return res;
    }
    void dfs2(int u, int par, int x, int& res, int tot) {
        res = min(res, x);
        int req = 0;
        for(auto& v : adj[u]) {
            if(move(u,v,tot)) req += 2;
        }
        for(auto& v : adj[u]) {
            if(v == par) continue;
            int xx = x + req - (move(u,v,tot) ? 4 : 0) + (move(v,u,tot) ? 4 : 0);
            dfs2(v,u,xx,res,tot);
        }
    }
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        for(int i = 0; i < coins.size(); i++) {
            c[i] = coins[i];
            sub[i] = dp[i] = 0;
        }
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int tot = dfs1(0,-1);
        int x = dfs0(0,-1,tot);
        int res = x;
        dfs2(0,-1,x,res,tot);
        return res;
    }
};