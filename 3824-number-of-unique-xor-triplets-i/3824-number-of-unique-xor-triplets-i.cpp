class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        return n <= 2 ? n : pow(2, 64 - __builtin_clzll(n));
    }
};
