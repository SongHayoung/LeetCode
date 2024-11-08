class Solution {
    int helper(int k, int ma) {
        int res = 0;
        for(int i = 0; i < ma; i++) {
            if(k & (1<<i)) continue;
            res ^= (1<<i);
        }
        return res;
    }
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int pxor = 0;
        for(auto& n : nums) pxor ^= n;
        vector<int> res;
        for(int i = nums.size() - 1; i >= 0; i--) {
            res.push_back(helper(pxor, maximumBit));
            pxor ^= nums[i];
        }
        return res;
    }
};