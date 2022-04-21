class Solution {
    int dp[15][1<<15];
    vector<pair<int, int>> adj[15];
    int helper(int u, int mask, int k) {
        if(k == 0) return 0;
        if(dp[u][mask] != -1) return dp[u][mask];
        int& res = dp[u][mask] = INT_MIN;

        for(auto& [v, w] : adj[u]) {
            if(mask & (1<<v)) continue;
            auto ans = helper(v, mask | (1<<v), k - 1);
            if(ans >= 0)
                res = max(res, ans + w);
        }
        
        return res;
    }
public:
    int maximumCost(int n, vector<vector<int>>& H, int k) {
        if(k > n) return -1;
        memset(dp,-1,sizeof(dp));
        for(auto& h : H) {
            adj[h[0]].push_back({h[1],h[2]});
            adj[h[1]].push_back({h[0],h[2]});
        }
        int res = INT_MIN;
        for(int i = 0; i < n; i++) {
            res = max(res, helper(i, 1<<i, k));
        }
        return res != INT_MIN ? res : -1;
    }
};