class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = 2, m = grid[0].size();
        vector<long long> dp(m + 1), dpp(m + 1);
        for(int i = 0; i < m; i++) {
            dp[i+1] = dp[i] + grid[0][i];
            dpp[i+1] = dpp[i] + grid[1][i];
        }
        long long res = LLONG_MAX;
        for(int i = 0; i < m; i++) {
            long long up = dp[m] - dp[i+1];
            long long down = dpp[i];
            long long ma = max(up,down);
            res = min(res, ma);
        }
        return res;
    }
};