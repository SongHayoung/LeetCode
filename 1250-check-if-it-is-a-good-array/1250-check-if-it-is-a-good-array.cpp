class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = nums[0];
        for(auto& x : nums) g = gcd(g,x);
        return g == 1;
    }
};