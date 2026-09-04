class Solution {
public:
    long long maxSum(vector<int>& nums, int k, long long mul) {
        sort(rbegin(nums), rend(nums));
        long long res = 0;
        for(int i = 0; i < k; i++) {
            res += nums[i] * max(1ll, mul);
            mul--;
        }
        return res;
    }
};