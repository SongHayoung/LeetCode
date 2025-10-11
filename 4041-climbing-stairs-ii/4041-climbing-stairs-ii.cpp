class Solution {
public:
    int climbStairs(int n, vector<int>& cost) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j <= n and j <= i + 3; j++) {
                dp[j] = min(dp[j], dp[i] + cost[j-1] + (j - i) * (j - i));
            }
        }
        
        return dp[n];
    }
};