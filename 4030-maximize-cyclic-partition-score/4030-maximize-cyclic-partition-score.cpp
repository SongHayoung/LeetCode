class Solution {
    long long helper(vector<int>& A, int k, int op) {
        vector<vector<long long>> dp(2 * k + 1, vector<long long>(3,-1e18));
        dp[0][op] = 0;
        for(int i = 0; i < A.size(); i++) {
            for(int j = 2 * k - 1; j >= 0; j--) {
                for(int l = 0; l < 3; l++) {
                    if(l + 1 < 3) dp[j+1][l+1] = max(dp[j+1][l+1], dp[j][l] + A[i]);
                    if(l) dp[j+1][l-1] = max(dp[j+1][l-1], dp[j][l] - A[i]);
                }
            }
        }
        long long res = LLONG_MIN;
        for(int i = 0; i <= 2 * k; i += 2) res = max(res, dp[i][op]);
        return res;
    }

public:
    long long maximumScore(vector<int>& nums, int k) {
        return max({helper(nums,k,0), helper(nums,k,1), helper(nums,k,2)});
    }
};