class Solution {
public:
    int minOperations(string A, string B) {
        int n = A.size(), m = B.size(), ma = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i] == B[j]) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                    ma = max(ma, dp[i+1][j+1]);
                }
            }
        }
        return n + m - 2 * ma;
    }
};