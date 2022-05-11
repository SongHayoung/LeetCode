class Solution {
    int dp[51][5];
    int helper(int n, int m) {
        if(n == -1) return 1;
        if(m == -1) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        dp[n][m] = 0;
        for(int i = 0; i <= m; i++)
            dp[n][m] += helper(n - 1, i);
        return dp[n][m];
    }
public:
    int countVowelStrings(int n) {
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= 4; j++) {
                for(int k = 0; k <= j; k++) {
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
        return dp[n][4] + dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3];
    }
};