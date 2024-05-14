class Solution {
public:
    int numberOfPaths(vector<vector<int>>& A, int k) {
        int n = A.size(), m = A[0].size();
        long long mod = 1e9 + 7;
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(m, vector<long long>(k)));
        dp[0][0][A[0][0] % k] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int d = 0; d < k; d++) {
                    if(i) {
                        dp[i][j][(d + A[i][j]) % k] = (dp[i-1][j][d] + dp[i][j][(d + A[i][j]) % k]) % mod;
                    }
                    if(j) {
                        dp[i][j][(d + A[i][j]) % k] = (dp[i][j-1][d] + dp[i][j][(d + A[i][j]) % k]) % mod;
                    }
                }
            }
        }
        return dp[n-1][m-1][0];
    }
};