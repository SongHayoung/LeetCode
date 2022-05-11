class Solution {
    int dp[50][5];
    int helper(int n, int m) {
        if(n == -1) return 1;
        if(m == -1) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        dp[n][m] = 0;
        for(int i = 0; i <= m; i++)
            dp[n][m] += helper(n - 1, i);
        return dp[n][m];
    }
public:
    int countVowelStrings(int n) {
        memset(dp, -1, sizeof dp);
        return helper(n-1,4);
    }
};