class Solution {
public:
    int minOperations(vector<int>& nums) {
        return *max_element(begin(nums), end(nums)) != *min_element(begin(nums), end(nums));
    }
};