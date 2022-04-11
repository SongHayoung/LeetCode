class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, res = INT_MIN;
        for(auto& n : nums) {
            sum = max(n, sum + n);
            res = max(res, sum);
        }
        return res;
    }
};