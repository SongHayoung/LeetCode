class Solution {
public:
    int maxNonOverlapping(vector<int>& A, int target) {
        unordered_map<int, int> psum;
        int n = A.size(), res = 0;
        vector<int> dp(n);
        for(int i = 0, sum = 0; i < n; i++) {
            sum += A[i];
            int k = sum - target;
            if(psum.count(k)) {
                dp[i] = dp[psum[k]] + 1;
            } else if(k == 0) dp[i] = 1;
            psum[sum] = i;
            if(i) dp[i] = max(dp[i], dp[i-1]);
            res = max(res, dp[i]);
        }
        return res;
    }
};