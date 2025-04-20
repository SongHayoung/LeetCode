class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> dp(k), res(k);
        for(auto& n : nums) {
            vector<long long> dpp(k);
            dpp[n % k] = 1;
            for(long long i = 0; i < k; i++) dpp[i * n % k] += dp[i];
            for(long long i = 0; i < k; i++) res[i] += dpp[i];
            swap(dp,dpp);
        }
        return res;
    }
};
