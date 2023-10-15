class Solution {
    int dp[251][501];
    int mod = 1e9 + 7;
    int helper(int n, int i, int step) {
        if(step == 0) return i == 0;
        if(dp[i][step] != -1) return dp[i][step];
        return dp[i][step] = ((helper(n, i, step - 1) + (i - 1 >= 0 ? helper(n, i - 1, step - 1) : 0)) % mod + (i + 1 < n ? helper(n, i + 1, step - 1) : 0)) % mod;
    }
public:
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        return helper(min(steps/2 + 1, arrLen), 0, steps);
    }
};