class Solution {
    long long dfs(int u, int par, vector<vector<int>>& adj, vector<int>& good, vector<int>& res, int tot) {
        res[u] = good[u] ? 1 : -1;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            auto sub = dfs(v,u,adj,good,res,tot);
            if(sub > 0) res[u] += sub;
        }
        return res[u];
    }
    void dfs2(int u, int par, vector<vector<int>>& adj,  vector<int>& good, vector<int>& res, int parSum) {
        res[u] += parSum;
        parSum += good[u] ? 1 : -1;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            if(res[v] > 0) parSum += res[v];
        }
        for(auto& v : adj[u]) {
            if(v == par) continue;
            int best = parSum;
            if(res[v] > 0) best -= res[v];
            dfs2(v,u,adj,good,res,max(0,best));
        }
    }
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        vector<int> res(n);
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int tot = 2 * accumulate(begin(good), end(good), 0) - n;
        dfs(0,-1,adj,good,res,tot);
        dfs2(0,-1,adj,good,res,0);
        return res;
    }
};