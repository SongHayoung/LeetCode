class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax = 0, maxSum = INT_MIN, curMin = 0, minSum = INT_MAX, tot = 0;
        for(auto& n : nums) {
            curMax = max(curMax + n, n);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + n, n);
            minSum = min(minSum, curMin);
            tot += n;
        }

        return tot == minSum ? maxSum : max(maxSum, tot - minSum);
    }
};