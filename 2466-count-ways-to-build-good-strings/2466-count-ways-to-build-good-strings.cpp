const long long mod = 1e9 + 7;
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long long> dp(high + 1,0);
        dp[0] = 1;
        long long res = 0;
        for(int i = 1; i <= high; i++) {
            if(i >= zero) dp[i] = (dp[i-zero] + dp[i]) % mod;
            if(i >= one) dp[i] = (dp[i-one] + dp[i]) % mod;
            if(i >= low) res = (res + dp[i]) % mod;
        }
        return res;
    }
};
