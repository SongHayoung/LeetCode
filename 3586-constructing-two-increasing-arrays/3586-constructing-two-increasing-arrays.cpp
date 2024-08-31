class Solution {
public:
    int minLargest(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, (n + 1) * (m + 1) * 2));
        dp[0][0] = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i < n) {
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j] + ((A[i] ^ dp[i][j]) & 1 ? 1 : 2));
                }
                if(j < m) {
                    dp[i][j+1] = min(dp[i][j+1], dp[i][j] + ((B[j] ^ dp[i][j]) & 1 ? 1 : 2));
                }
            }
        }
        return dp[n][m];
    }
};
