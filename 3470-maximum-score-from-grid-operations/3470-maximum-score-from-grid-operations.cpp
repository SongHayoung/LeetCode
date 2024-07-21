
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
        long long op = 0;
        for(int i = 0; i <= n; i++) dp[1][0][i] = 0;
        for(int col = 1; col < n; col++) {
            for(int x = 0; x <= n; x++) {
                for(int y = 0; y <= n; y++) {
                    if(dp[col][x][y] == -1) continue;
                    int ma = max(x,y);
                    for(int z = 0; z < y; z++) {
                        dp[col+1][y][z] = max(dp[col+1][y][z], dp[col][x][y] + pre[y][col] - pre[z][col]);
                    }
                    for(int z = y; z <= ma; z++) {
                          dp[col+1][y][z] = max(dp[col+1][y][z], dp[col][x][y]);
                    }
                    for(int z = ma + 1; z <= n; z++) {
                        dp[col+1][y][z] = max(dp[col+1][y][z], dp[col][x][y] + pre[z][col-1] - pre[ma][col-1]);
                    }
                }
            }
        }
        long long res = 0;
        for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) res = max(res, dp[n][i][j]);
        return res;
    }
};