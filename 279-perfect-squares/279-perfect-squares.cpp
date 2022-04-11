class Solution {
    int dp[10001];
    int solution(int n) {
        if(dp[n] != -1) return dp[n];
        if(((int)sqrt(n)) * ((int)sqrt(n)) == n) return dp[n] = 1;
        dp[n] = INT_MAX;
        for(int i = 1; i * i <= n; i++) {
            dp[n] = min(dp[n], solution(n - i * i) + 1);
        }
        return dp[n];
    }
public:
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solution(n);
    }
};