class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        long long res = 0, now = 2;
        for(int i = 0; i + 2 < nums.size(); i++) {
            long long expect = nums[i] + nums[i+1];
            now = nums[i+2] == expect ? now + 1 : 2;
            res = max(res, now);
        }
        return res;
    }
};