class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int res = 0;
        for(auto& n : arr) {
            res = max(res, dp[n] = dp[n-difference] + 1);
        }
        return res;
    }
};