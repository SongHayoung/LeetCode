class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        long long mod = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(goal + 1, 0));
        dp[0][0] = 1;
        for(long long i = 1; i <= n; i++) {
            for(long long j = 1; j <= goal; j++) {
                dp[i][j] = (dp[i-1][j-1] * (n - (i - 1)) + dp[i][j - 1] * (max(0ll, i - k))) % mod;
            }
        }
        return dp[n][goal];
    }
};