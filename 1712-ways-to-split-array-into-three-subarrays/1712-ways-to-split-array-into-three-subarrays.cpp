class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        long res = 0;
        partial_sum(begin(nums), end(nums), begin(nums));
        for(auto left = 0, midBegin = 0, midEnd = 0; left < nums.size() - 2 && nums[left] * 3 <= nums.back(); ++left) {
            while(midBegin <= left || (midBegin < nums.size() - 1 && nums[left]<<1 > nums[midBegin])) ++midBegin;
            while(midBegin > midEnd || (midEnd < nums.size() - 1 && nums[midEnd]<<1 <= nums.back() + nums[left])) ++midEnd;
            res += midEnd - midBegin;
        }
        return res % 1000000007;
    }
};