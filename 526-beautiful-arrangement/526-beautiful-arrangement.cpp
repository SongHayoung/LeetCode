class Solution {
    int dp[1<<16];
    int backTracking(int& n, int perm, int mask) {
        if(perm == n + 1) {
            return 1;
        }
        if(dp[mask]!=-1) return dp[mask];
        dp[mask] = 0;
        for(int i = 1; i <= n; i++) {
            if(mask & (1<<i)) continue;
            if(perm % i == 0 or i % perm == 0) {
                dp[mask] += backTracking(n, perm + 1, mask | (1<<i));
            }
        }
        return dp[mask];
    }
public:
    int countArrangement(int n) {
        memset(dp,-1,sizeof(dp));
        return backTracking(n, 1, 0);
    }
};