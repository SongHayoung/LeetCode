class Solution {
    int dp[1<<8];
    bool bit(int bit, int x) {
        return (bit>>x) & 1;
    }
    int helper(vector<int>& A, int mask, int cost, int k) {
        if(dp[mask] != -1) return dp[mask];
        int& res = dp[mask] = INT_MAX;
        for(int i = 0; i < A.size(); i++) {
            if(bit(mask,i)) continue;
            res = min(res, helper(A,mask | 1<<i, cost + k, k) + (A[i] + cost - 1) / cost);
        }
        return res;
    }
public:
    int findMinimumTime(vector<int>& strength, int K) {
        memset(dp, -1, sizeof dp);
        dp[(1<<strength.size()) - 1] = 0;
        return helper(strength, 0, 1, K);
    }
};