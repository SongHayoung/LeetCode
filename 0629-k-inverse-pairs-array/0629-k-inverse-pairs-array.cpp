class Solution {
    long long dp[1010][1010], mod = 1e9 + 7;
public:
    int kInversePairs(int n, int k) {
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= k; j++) {
                dp[i][j] = (dp[i-1][j] + (j ? dp[i][j-1] : 0)) % mod;
                if(j >= i) dp[i][j] = (mod + dp[i][j] - dp[i-1][j-i]) % mod;
            }
        }
        return dp[n][k];
    }
};