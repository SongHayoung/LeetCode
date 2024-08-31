class Solution {
public:
    int minLargest(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, (n + 1) * (m + 1) * 2));
        dp[0][0] = 0;
        auto helper = [&](int x, int fl) {
            if(x % 2 == fl % 2) return x + 2;
            return x + 1;
        };
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i < n) {
                    dp[i+1][j] = min(dp[i+1][j], helper(dp[i][j], A[i]));
                }
                if(j < m) {
                    dp[i][j+1] = min(dp[i][j+1], helper(dp[i][j], B[j]));
                }
            }
        }
        return dp[n][m];
    }
};

