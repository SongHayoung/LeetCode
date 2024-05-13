class Solution {
    int dp[1<<14];
    vector<int> c;
    bool bit(int x, int k) {
        return (x>>k) & 1;
    }
    int helper(vector<int>& A, int mask, int t) {
        int n = A.size();
        if(dp[mask] != -1) return dp[mask];
        int& res = dp[mask] = 22;
        for(auto& x : c) {
            if(mask & x) continue;
            res = min(res, 1 + helper(A, mask | x, t));
        }
        return res;
    }
public:
    int minSessions(vector<int>& A, int sessionTime) {
        int n = A.size();
        memset(dp,-1,sizeof dp);
        dp[(1<<n) - 1] = 0;
        c = {};
        for(int i = 1; i < 1<<n; i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                if(bit(i,j)) sum += A[j];
            }
            if(sum <= sessionTime) c.push_back(i);
        }
        return helper(A,0,sessionTime);
    }
};