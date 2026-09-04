class Solution {
public:
    long long minArraySum(vector<int>& nums, int k) {
        vector<long long> best(k, LLONG_MIN);
        best[0] = 0;
        long long n = nums.size(), pre = 0, dp = 0;
        for(int i = 0; i < n; i++) {
            pre += nums[i];
            long long dpp = dp;
            if(best[pre % k] != LLONG_MIN) {
                dpp = max(dpp, best[pre % k] + pre);
            }
            best[pre % k] = max(best[pre % k], dpp - pre);
            dp = dpp;
        }
        return pre - dp;
    }
};