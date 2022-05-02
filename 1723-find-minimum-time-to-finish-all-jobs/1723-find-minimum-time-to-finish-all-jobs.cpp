class Solution {
public:
    int minimumTimeRequired(vector<int>& A, int k) {
        int n = A.size();
        vector<int> subset(1<<n, 0);
        for(int i = 1; i < (1<<n); i++) {
            for(int j = 0; j < n; j++) {
                if(i & (1<<j)) subset[i] += A[j];
            }
        }
        
        vector<vector<int>> dp(k, vector<int>(1<<n));
        dp[0] = subset;
        for(int i = 1; i < k; i++) {
            for(int j = 0; j < (1<<n); j++) {
                dp[i][j] = dp[i-1][j];
                for(int k = j; k; k = (k - 1) & j) {
                    dp[i][j] = min(dp[i][j], max(subset[k], dp[i-1][j ^ k]));
                }
            }
        }
        return dp.back().back();
    }
};