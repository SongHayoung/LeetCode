


long long dp[102][102][102];
long long pre[102][102];
class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof dp);
        int n = grid.size();
        if(n == 1) return 0;

        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
            pre[i+1][j] = pre[i][j] + grid[i][j];
        }
        for(int i = 0; i <= n; i++) dp[1][0][i] = 0;
        for(int col = 1; col < n; col++) {
            for(int x = 0; x <= n; x++) {
                for(int y = 0; y <= n; y++) {
                    if(dp[col][x][y] == -1) continue;
                    int t = max(x,y);
                    for(int k = t + 1; k <= n; k++) {
                        dp[col+1][y][k] = max(dp[col+1][y][k], dp[col][x][y] + pre[k][col-1] - pre[t][col-1]);
                    }
                    for(int k = 0; k < y; k++) {
                        dp[col+1][y][k] = max(dp[col+1][y][k], dp[col][x][y] + pre[y][col] - pre[k][col]);
                    }
                    for(int k = y; k <= t; k++) {
                        dp[col+1][y][k] = max(dp[col+1][y][k], dp[col][x][y]);
                    }
                }
            }
        }
        long long res = 0;
        for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) res = max(res, dp[n][i][j]);
        return res;
    }
};