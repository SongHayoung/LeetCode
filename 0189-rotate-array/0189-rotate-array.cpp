class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if(!k) return;
        k = nums.size() - k;
        reverse(begin(nums), begin(nums) + k);
        reverse(begin(nums) + k, end(nums));
        reverse(begin(nums), end(nums));
    }
};