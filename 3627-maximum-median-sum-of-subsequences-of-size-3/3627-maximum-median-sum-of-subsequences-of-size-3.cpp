class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        long long res = 0;
        for(int i = n / 3; i < n; i += 2) res += nums[i];
        return res;
    }
};