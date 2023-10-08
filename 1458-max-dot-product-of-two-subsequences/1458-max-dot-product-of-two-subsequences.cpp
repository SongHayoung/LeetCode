class Solution {
    vector<vector<int>> dp;
    int helper(vector<int>& nums1, vector<int>& nums2, int i, int j) {
        if(i == nums1.size() or j == nums2.size()) return INT_MIN;
        if(dp[i][j] != INT_MIN) return dp[i][j];
        dp[i][j] = max({
            helper(nums1, nums2, i + 1, j),
            helper(nums1, nums2, i, j + 1),
            max(helper(nums1, nums2, i + 1, j + 1),0) + nums1[i]*nums2[j]
            });
        return dp[i][j];
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dp = vector<vector<int>>(nums1.size() + 1, vector<int>(nums2.size() + 1, INT_MIN));
        return helper(nums1, nums2, 0, 0);
    }
};