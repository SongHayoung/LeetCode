class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long res = *max_element(begin(nums), end(nums)), n = nums.size();
        vector<long long> suf(n + 1);
        for(int i = n - 1; i >= 0; i--) {
            suf[i] = max(suf[i], suf[i+1] + nums[i]);
        }
        vector<long long> dp(3, 0);
        for(int i = 0; i < n; i++) {
            vector<long long> dpp(3, 0);
            dpp[0] = max(0ll,dp[0]) + nums[i];
            dpp[1] = max({0ll,dp[0], dp[1]}) + 1ll * nums[i] * k;
            dpp[2] = max({0ll,dp[0], dp[2]}) + 1ll * nums[i] / k;
            res = max(res, *max_element(begin(dpp), end(dpp)) + suf[i+1]);
            swap(dp,dpp);
        }
        return res;
    }
};
