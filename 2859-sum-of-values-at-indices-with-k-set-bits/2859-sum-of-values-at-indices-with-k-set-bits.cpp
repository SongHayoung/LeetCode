class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(__builtin_popcount(i) == k) res += nums[i];
        }
        return res;
    }
};