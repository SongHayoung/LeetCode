class Solution {
public:
    int distinctSubseqII(string s) {
        long dp[27] = {0,}, mod = 1e9+7, res = 0, sum = 0;
        for(auto& ch : s) {
            long tot = (1 + sum) % mod;
            sum = (sum - dp[ch-'a'] + tot + mod) % mod;
            dp[ch-'a'] = tot;
        }
        return sum;
    }
};