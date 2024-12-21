class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        long long n = grid.size(), m = grid[0].size(), mod = 1e9 + 7;
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(64)));
        dp[0][0][grid[0][0]] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < 64; k++) {
                    if(i + 1 < n) {
                        dp[i+1][j][k ^ grid[i+1][j]] = (dp[i+1][j][k ^ grid[i+1][j]] + dp[i][j][k]) % mod;
                    }
                    if(j + 1 < m) {
                        dp[i][j+1][k ^ grid[i][j+1]] = (dp[i][j+1][k ^ grid[i][j+1]] + dp[i][j][k]) % mod;
                    }
                }
            }
        }
        return dp[n-1][m-1][k];
    }
};