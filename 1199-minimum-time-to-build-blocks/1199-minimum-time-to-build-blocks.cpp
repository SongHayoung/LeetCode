class Solution {
    int dp[1010][2020];
    int helper(vector<int>& A, int pos, int worker, int& split) {
        if(pos < 0) return 0;
        if(worker > pos) return A[pos];
        if(worker == 0) return 987654321;
        if(dp[pos][worker] != -1) return dp[pos][worker];
        int& res = dp[pos][worker] = split + helper(A, pos, worker * 2, split);
        res = min(res, max(A[pos], helper(A, pos - 1, worker - 1, split)));
        return res;
    }
public:
    int minBuildTime(vector<int>& A, int split) {
        memset(dp, -1, sizeof dp);
        sort(begin(A), end(A));
        
        return helper(A, A.size() - 1, 1, split);
    }
};