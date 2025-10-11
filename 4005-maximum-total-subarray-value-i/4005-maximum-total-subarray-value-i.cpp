class Solution {
public:
    long long maxTotalValue(vector<int>& nums, long long k) {
        return k * (*max_element(begin(nums), end(nums)) - *min_element(begin(nums), end(nums)));
    }
};