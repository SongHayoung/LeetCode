class Solution {
    long long mod = 1e9 + 7;
    long long helper(vector<int>& nums, int op) {
        unordered_map<long long, pair<long long, long long>> dp;
        long long res = 0;
        for(auto& n : nums) {
            long long sum = 0, cnt = 1;
            if(dp.count(n + op)) {
                sum = (sum + dp[n + op].first) % mod;
                cnt = (cnt + dp[n + op].second) % mod;
            }
            sum = (sum + cnt * n % mod) % mod;
            dp[n].first = (dp[n].first + sum) % mod;
            dp[n].second = (dp[n].second + cnt) % mod;
        }
        for(auto& [_,p] : dp) res = (res + p.first) % mod;
        return res;
    }
public:
    int getSum(vector<int>& nums) {
        return (helper(nums, 1) + helper(nums, -1) - accumulate(begin(nums), end(nums), 0ll) % mod + mod) % mod;
    }
};