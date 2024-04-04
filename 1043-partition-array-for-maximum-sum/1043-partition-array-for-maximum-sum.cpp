class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int k) {
        vector<int> dp(A.size() + 1);
        for(int i = A.size() - 1; i >= 0; i--) {
            int ma = 0;
            for(int j = i; j < i + k and j < A.size(); j++) {
                ma = max(ma, A[j]);
                dp[i] = max(dp[i], ma * (j - i + 1) + dp[j+1]);
            }
        }
        return dp[0];
    }
};