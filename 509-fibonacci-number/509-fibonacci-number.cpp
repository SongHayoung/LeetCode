class Solution {
    int dp[31] = {0,};
public:
    int fib(int n) {
        if(n <= 1) return n;
        if(dp[n]) return dp[n];
        return dp[n] = fib(n-1) + fib(n-2);
    }
};