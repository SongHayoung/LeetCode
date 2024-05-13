class Solution {
    vector<long long> dfs(vector<vector<pair<long long,long long>>>& adj, int u) {
        vector<long long> res{0,0};
        long long best = 0, sum = 0;
        vector<vector<long long>> dp;
        for(auto& [v,w] : adj[u]) {
            auto sub = dfs(adj,v);
            dp.push_back({w + sub[1], sub[0]});
            best += max(sub[0], sub[1]);
            sum += sub[0];
        }
        for(int i = 0; i < dp.size(); i++) {
            res[0] = max(res[0], sum + dp[i][0] - dp[i][1]);
        }
        res[0] = max(res[0], best);
        res[1] = best;
        return res;
    }
public:
    long long maxScore(vector<vector<int>>& edges) {
        vector<vector<pair<long long,long long>>> adj(edges.size());
        int root;
        for(int u = 0; u < edges.size(); u++) {
            if(edges[u][0] == -1) root = u;
            else adj[edges[u][0]].push_back({u, max(0,edges[u][1])});
        }
        auto res = dfs(adj,root);
        return max(res[0], res[1]);
    }
};