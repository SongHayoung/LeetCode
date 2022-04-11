class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int cols{(int)grid[0].size()}, rows{(int)grid.size()}, mod = 1e9 + 7;
        pair<long, long> dp[15][15];
        dp[0][0].first = dp[0][0].second = grid[0][0];
        for(int i = 1; i < rows; i++) {
            dp[i][0].first = dp[i][0].second = dp[i - 1][0].first * grid[i][0];
        }

        for(int i = 1; i < cols; i++) {
            dp[0][i].first = dp[0][i].second = dp[0][i - 1].first * grid[0][i];
        }
        
        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < cols; j++) {
                dp[i][j].first = (grid[i][j] < 0 ? min(dp[i - 1][j].second, dp[i][j - 1].second) : max(dp[i - 1][j].first, dp[i][j - 1].first))  * grid[i][j];
                dp[i][j].second = (grid[i][j] < 0 ? max(dp[i - 1][j].first, dp[i][j - 1].first) : min(dp[i-1][j].second, dp[i][j - 1].second)) * grid[i][j];
            }
        }
        return max((long)-1, dp[rows - 1][cols - 1].first) % mod;
    }
};
