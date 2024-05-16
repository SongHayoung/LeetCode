class Solution {
    long long cost[12][12], n;
    long long dp[1<<12][12];
    bool bit(int x, int p) {
        return (x>>p) & 1;
    }
    long long helper(int mask, int u) {
        if(mask + 1 == (1<<n)) return 0;
        if(dp[mask][u] != -1) return dp[mask][u];
        long long& res = dp[mask][u] = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(bit(mask,i)) continue;
            res = min(res, cost[u][i] + helper(mask | (1<<i), i));
        }
        return res;
    }
public:
    int shortestPathLength(vector<vector<int>>& E) {
        n = E.size();
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
            cost[i][j] = INT_MAX;
        }
        for(int i = 0; i < n; i++) cost[i][i] = 0;
        for(int i = 0; i < n; i++) for(auto& x : E[i]) {
            cost[x][i] = cost[i][x] = 1;
        }
        for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
            cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
        }
        memset(dp,-1,sizeof dp);
        long long res = INT_MAX;
        for(int i = 0; i < n; i++) {
            res = min(res, helper(0,i));
        }
        return res;
    }
};