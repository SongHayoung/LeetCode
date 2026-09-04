class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long n = nums.size(), res = LLONG_MIN, pre = 0;
        vector<int> suf(n,nums.back());
        for(int i = n - 2; i; i--) suf[i] = min(suf[i+1], nums[i]);
        for(int i = 0; i < n - 1; i++) {
            pre += nums[i];
            res = max(res, pre - suf[i+1]);
        }
        return res;
    }
};