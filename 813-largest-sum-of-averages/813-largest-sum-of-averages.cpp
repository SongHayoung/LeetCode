class Solution {
    double dp[111][111];
    double helper(vector<long long>& A, int pos, int k) {
        if(pos + 1 == A.size()) return 0;
        if(k == 1) return 1.0 * (A.back() - A[pos]) / (A.size() - pos -1);
        if(dp[pos][k] > 0) return dp[pos][k];
        double& res = dp[pos][k];
        for(int i = pos + 1; i < A.size(); i++) {
            res = max(res, 1.0 * (A[i] - A[pos]) / (i - pos) + helper(A, i, k - 1));
        }
        return res;
    }
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        memset(dp, 0, sizeof dp);
        vector<long long> psum{0};
        for(auto& n : nums) psum.push_back(psum.back() + n);
        return helper(psum, 0, k);
    }
};