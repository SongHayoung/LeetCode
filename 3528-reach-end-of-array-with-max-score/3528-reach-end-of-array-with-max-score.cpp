class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long res = 0, ma = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            ma = max(ma, nums[i] * 1ll);
            res += ma;
        }
        return res;
    }
};