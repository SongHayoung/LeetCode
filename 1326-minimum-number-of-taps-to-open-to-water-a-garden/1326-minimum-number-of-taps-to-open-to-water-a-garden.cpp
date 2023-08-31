class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n + 1, n + 2);
        dp[0] = 0;
        for(int i = 0; i <= n; i++) {
            for(int j = max(0, i - ranges[i]); j <= min(n, i + ranges[i]); j++) {
                dp[j] = min(dp[j], dp[max(0, i-ranges[i])] + 1);
            }
        }
        return dp.back() == n + 2 ? -1 : dp.back();
    }
};