class Solution {
    int dp[505];
    int helper(vector<int>& A, int k, int p) {
        if(p == A.size()) return 0;
        if(dp[p] != -1) return dp[p];
        int n = A.size();
        for(int i = p, ma = 0; i < min(n, p + k); i++) {
            ma = max(ma, A[i]);
            dp[p] = max(dp[p], ma * (i - p + 1) + helper(A, k, i + 1));
        }
        return dp[p];
    }
public:
    int maxSumAfterPartitioning(vector<int>& A, int k) {
        memset(dp, -1, sizeof dp);
        return helper(A,k,0);
    }
};