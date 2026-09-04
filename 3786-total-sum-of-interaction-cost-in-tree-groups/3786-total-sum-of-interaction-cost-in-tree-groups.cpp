class Solution {
    unordered_map<int,pair<long long,long long>> dfs(int u, int par, vector<vector<int>>& adj, vector<int>& g, long long& res) {
        unordered_map<int,pair<long long,long long>> acc;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            auto sub = dfs(v,u,adj,g,res);
            for(auto& [k,p] : sub) {
                if(k == g[u]) res += p.first;
                if(acc.contains(k)) {
                    res += acc[k].second * p.first;
                    res += p.second * acc[k].first;
                }
                acc[k].first += p.first;
                acc[k].second += p.second;
            }
        }
        acc[g[u]].second += 1;
        for(auto& [_,p] : acc) {
            p.first += p.second;
        }
        return acc;
    }
public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long res = 0;
        dfs(0,-1,adj,group,res);
        return res;
    }
};