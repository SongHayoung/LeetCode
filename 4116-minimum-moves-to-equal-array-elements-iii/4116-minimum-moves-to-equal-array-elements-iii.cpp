class Solution {
public:
    int minMoves(vector<int>& nums) {
        return *max_element(begin(nums), end(nums)) * nums.size() - accumulate(begin(nums), end(nums), 0);
    }
};