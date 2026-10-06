class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        long long n = nums.size(), sum = accumulate(begin(nums), end(nums), 0ll), half = accumulate(begin(nums), begin(nums) + n / 2, 0ll);
        int res = 0;
        for(int i = 0; i < n; i++) {
            long long oth = sum - half;
            if(oth < half) res++;
            half = half - nums[i] + nums[(i + n / 2) % n];
        }
        return res;
    }
};