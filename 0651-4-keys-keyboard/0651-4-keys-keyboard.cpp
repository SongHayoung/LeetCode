class Solution {
public:
    int maxA(int n) {
        vector<int> dp(n + 3);
        for(int i = 1; i <= n; i++) {
            dp[i] = i;
            for(int j = 1; j < i - 2; j++) {
                dp[i] = max(dp[i], dp[j]*(i-j-1));
            }
        }
        return dp[n];
    }
};