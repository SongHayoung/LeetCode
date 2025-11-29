class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        for(auto& n : nums) res = (res + n) % k;
        return res;
    }
};