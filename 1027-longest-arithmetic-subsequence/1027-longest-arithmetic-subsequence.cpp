class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<vector<int>> dp(n, vector<int>(1001, 0));
        unordered_map<int, int> counter;
        for(int i = 0; i < n; i++) {
            for(auto [value, index] : counter) {
                int diff = nums[i] - value + 500;
                res = max(res, dp[i][diff] = max(dp[index][diff] + 1, dp[i][diff]));
            }
            counter[nums[i]] = i;
        }
        return res + 1;
    }
};