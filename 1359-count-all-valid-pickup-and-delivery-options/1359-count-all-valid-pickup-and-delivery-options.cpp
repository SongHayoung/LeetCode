class Solution {
    long dp[501][501];
    int mod = 1e9 + 7;
    long factorials[501];
    long helper(int pickUp, int delivery) {
        if(delivery < 0) return 0;
        if(pickUp == 0) return factorials[delivery];
        
        if(dp[pickUp][delivery] != -1) return dp[pickUp][delivery];
        dp[pickUp][delivery] = (helper(pickUp - 1, delivery + 1) * pickUp % mod + helper(pickUp, delivery - 1) * delivery % mod) % mod;
        return dp[pickUp][delivery];
    }
public:
    int countOrders(int n) {
        memset(dp,-1,sizeof(dp));
        factorials[1] = 1;
        factorials[0] = 0;
        for(int i = 2; i <= n; i++) {
            factorials[i] = (factorials[i - 1] * i) % mod;
        }
        return helper(n,0);
    }
};