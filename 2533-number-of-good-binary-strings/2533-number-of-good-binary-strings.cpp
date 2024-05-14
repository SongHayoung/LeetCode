class Solution {
public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        vector<long long> dp(maxLength + 1);
        dp[0] = 1;
        long long mod = 1e9 + 7, res = 0;
        for(int i = 0; i < dp.size(); i++) {
            if(!dp[i]) continue;
            if(i >= minLength) res = (res + dp[i]) % mod;
            if(i + oneGroup <= maxLength) {
                dp[i+oneGroup] = (dp[i+oneGroup] + dp[i]) % mod;
            }
            if(i + zeroGroup <= maxLength) {
                dp[i+zeroGroup] = (dp[i+zeroGroup] + dp[i]) % mod;
            }
        }
        return res;
    }
};