class Solution {
    long long dp[222][222];
    long long helper(vector<int>& A, int p, int k) {
        if(p + k >= A.size()) return 0;
        if(k < 0) return INT_MAX;
        long long& res = dp[p][k];
        if(res != -1) return res;
        res = helper(A, p + 1, k - 1);
        long long sum = A[p], ma = A[p];
        for(int i = p + 1; i < A.size(); i++) {
            ma = max(ma, 1ll * A[i]);
            sum += A[i];
            res = min(res, ma * (i - p + 1) - sum + helper(A,i+1,k-1));
        }
        return res;
    }
public:
    int minSpaceWastedKResizing(vector<int>& A, int k) {
        memset(dp,-1,sizeof dp);
        return helper(A, 0, k + 1);
    }
};