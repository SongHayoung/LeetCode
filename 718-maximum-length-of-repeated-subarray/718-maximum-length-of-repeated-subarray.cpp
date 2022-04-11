class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res(0), n(nums1.size()), m(nums2.size());
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(nums1[i] == nums2[j]) res = max(res, dp[i + 1][j + 1] = dp[i][j] + 1);
            }
        }
        return res;
    }
};