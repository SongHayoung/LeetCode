class Solution {
    void dfs1(int u, int d, int p, vector<int>& dep, vector<int>& par, vector<vector<int>>& adj) {
        par[u] = p;
        dep[u] = d;
        for(auto v : adj[u]) {
            if(v == p) continue;
            dfs1(v,d+1,u,dep,par,adj);
        }
    }
    void dfs2(int u, int now, int par, int& res, vector<vector<int>>& adj, vector<int>& cost) {
        now += cost[u];
        bool fl = true;
        for(auto v : adj[u]) {
            if(v == par) continue;
            dfs2(v,now,u,res,adj,cost);
            fl = false;
        }
        if(fl) res = max(res,now);
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<vector<int>> adj(amount.size());
        for(auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dep(amount.size());
        vector<int> par(amount.size());
        dfs1(0,0,-1,dep,par,adj);
        int target = dep[bob], u = bob;
        amount[bob] = 0;
        for(int i = 0; i < (target + 1) / 2; i++) {
            amount[u] = 0;
            u = par[u];
        }
    
        if(target % 2 == 0) amount[u] /= 2;
        int res = INT_MIN;
        dfs2(0,0,-1,res,adj,amount);
        return res;
    }
};