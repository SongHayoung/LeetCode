class Solution {
public:
    int numMusicPlaylists(int n, int l, int k) {
        long long dp[101][101] = {1}, mod = 1e9 + 7;
        for(long long i = 1; i <= l; i++) {
            for(long long j = 1; j <= n; j++) {
                dp[i][j] = (dp[i-1][j-1] * (n - j + 1) + dp[i-1][j] * (max(0ll, j - k))) % mod;
            }
        }
        return dp[l][n];
    }
};