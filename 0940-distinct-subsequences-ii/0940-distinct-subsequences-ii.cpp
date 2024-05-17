class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long long> dp(26);
        long long mod = 1e9 + 7, sum = 0;
        for(auto& ch : s) {
            long long cnt = (1 + sum) % mod;
            sum = (sum - dp[ch-'a'] + cnt + mod) % mod;
            dp[ch-'a'] = cnt;
        }
        return sum;
    }
};