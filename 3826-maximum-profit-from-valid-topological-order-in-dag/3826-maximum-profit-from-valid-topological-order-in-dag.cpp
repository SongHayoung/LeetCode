int dp[1<<23];
class Solution {
    bool on(int mask, int u) {
        return (mask>>u) & 1;
    }
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        vector<int> adj(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[v] |= 1<<u;
        }
        dp[0] = 0;
        int ma = 1<<n;
        for(int mask = 1; mask < ma; mask++) {
            int ord = __builtin_popcount(mask);
            dp[mask] = -1e9;
            for(int u = 0; u < n; u++) {
                if(!on(mask,u)) continue;
                if((mask & adj[u]) != adj[u]) continue;
                dp[mask] = max(dp[mask], ord * score[u] + dp[mask ^ (1<<u)]);
            }
        }
        return dp[ma-1];
    }
};
