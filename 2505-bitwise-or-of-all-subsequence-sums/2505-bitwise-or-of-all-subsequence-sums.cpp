class Solution {
public:
    long long subsequenceSumOr(vector<int>& nums) {
        long long res = 0, psum = 0;
        for(auto n : nums) {
            psum += n;
            res |= n | psum;
        }
        return res;
    }
};