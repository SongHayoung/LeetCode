int dp[1<<23];
class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        vector<int> adj(n);
        for(auto& e : edges) adj[e[1]] |= 1<<e[0];
        for(int i = 0; i < n; i++) adj[i] |= 1<<i;
        int ma = 1<<n;
        for(int mask = 1; mask < ma; mask++) {
            int ord = __builtin_popcount(mask);
            dp[mask] = -1e9;
            for(int u = 0; u < n; u++) {
                if((mask & adj[u]) != adj[u]) continue;
                dp[mask] = max(dp[mask], ord * score[u] + dp[mask ^ (1<<u)]);
            }
        }
        return dp[ma-1];
    }
};