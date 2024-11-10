class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        unordered_map<long long, pair<long long, long long>> dp;
        long long mod = 1e9 + 7, res = 0;
        for(auto& x : nums) {
            long long cnt = 1, sum = 0;
            if(dp.count(x-1)) {
                cnt += dp[x-1].first;
                sum += dp[x-1].second;
            }
            if(dp.count(x+1)) {
                cnt += dp[x+1].first;
                sum += dp[x+1].second;
            }
            sum %= mod, cnt %= mod;
            sum = (sum + cnt * x % mod) % mod;
            res = (res + sum) % mod;
            dp[x].first = (dp[x].first + cnt) % mod;
            dp[x].second = (dp[x].second + sum) % mod;
        }
        return res;
    }
};