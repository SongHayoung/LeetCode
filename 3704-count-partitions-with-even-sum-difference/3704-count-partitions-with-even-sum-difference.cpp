class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int bit = 0;
        for(auto& n : nums) bit ^= n;
        return bit ? 0 : nums.size() - 1;
    }
};