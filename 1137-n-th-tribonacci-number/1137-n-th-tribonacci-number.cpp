class Solution {
    int dp[38] = {0,};
public:
    int tribonacci(int n) {
        if(n <= 2) return n ? 1 : 0;
        if(dp[n]) return dp[n];
        return dp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
    }
};