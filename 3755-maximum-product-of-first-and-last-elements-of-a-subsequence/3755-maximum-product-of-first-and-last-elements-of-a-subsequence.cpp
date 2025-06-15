class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        vector<long long> pos(n, nums.back()), neg(n, nums.back());
        for(int i = n - 1; i >= 0; i--) {
            pos[i] = max(pos[i], nums[i] * 1ll);
            neg[i] = min(neg[i], nums[i] * 1ll);
            if(i + 1 != n) {
                pos[i] = max(pos[i], pos[i+1]);
                neg[i] = min(neg[i], neg[i+1]);
            }
        }
        long long res = LLONG_MIN;
        for(int i = 0; i <= n - m; i++) {
            res = max({res, nums[i] * pos[i+m-1], nums[i] * neg[i+m-1]});
        }
        return res;
    }
};