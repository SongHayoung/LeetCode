class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int res = 0;
        for(auto n : nums) res ^= n;
        return res;
    }
};