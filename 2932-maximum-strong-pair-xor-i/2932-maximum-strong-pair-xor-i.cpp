class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int res = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(abs(nums[i] - nums[j]) <= min(nums[i], nums[j])) {
                    res = max(res, nums[i] ^ nums[j]);
                }
            }
        }
        return res;
    }
};