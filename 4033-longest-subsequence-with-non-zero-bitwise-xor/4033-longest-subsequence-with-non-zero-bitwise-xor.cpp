class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int bit = 0, notZero = 0;
        for(auto& n : nums) {
            if(n) {
                notZero++;
                bit ^= n;
            }
        }
        return bit ? nums.size() : notZero ? nums.size() - 1 : 0;
    }
};