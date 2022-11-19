class Solution {
    long long dp[1<<18];
    long long helper(vector<vector<int>>& cost, int day, int mask) {
        if(day == cost.size()) return 0;
        if(dp[mask] != -1) return dp[mask];
        long long& res = dp[mask] = LLONG_MAX;
        for(int i = 0; i < cost.size(); i++) {
            if(mask & (1<<i)) continue;
            res = min(res, cost[day][i] + helper(cost,day + 1, mask | (1<<i)));
        }
        return res;
    }
public:
    long long minimumTime(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> cost(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cost[i][j] = (A[j] + i) / (i + 1);
            }
        }
        memset(dp, -1, sizeof dp);
        return helper(cost, 0, 0);
    }
};
