class Solution {
public:
    int numTrees(int n) {
        int dp[20] = {0,};
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < i>>1; j++)
                dp[i] += dp[j] * dp[i-1-j];
            dp[i]<<=1;
            if(i & 1) dp[i] += dp[i>>1] * dp[i>>1];
        }

        return dp[n];
    }
};