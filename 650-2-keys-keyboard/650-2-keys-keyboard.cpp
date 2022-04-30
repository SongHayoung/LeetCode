class Solution {
    int dp[1001];
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 987654321);
        dp[1] = 0;
        for(int i = 1; i < n; i++) {
            for(int j = i + i; j <= n; j += i) {
                dp[j] = min(dp[j], dp[i] + j / i);
            }
        }
        return dp[n];
    }
};