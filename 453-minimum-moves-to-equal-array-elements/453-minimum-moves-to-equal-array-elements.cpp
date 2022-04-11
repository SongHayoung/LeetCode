class Solution {
public:
    int minMoves(vector<int>& nums) {
        return accumulate(begin(nums), end(nums), 0, [min = *min_element(begin(nums), end(nums))](int sum, int num) { return sum + num - min; });
    }
};