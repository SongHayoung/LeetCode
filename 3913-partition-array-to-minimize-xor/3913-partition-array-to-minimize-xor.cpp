
class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> dp(n+1, vector<long long>(k + 1, INT_MAX));
        dp[0][0] = 0;
        for(int i = 0; i < n; i++) {
            for(int op = 0; op < k; op++) {
                if(dp[i][op] == INT_MAX) continue;
                long long bit = 0;
                for(int j = i; j < n; j++) {
                    bit ^= nums[j];
                    dp[j+1][op+1] = min(dp[j+1][op+1], max(bit, dp[i][op]));
                }
            }
        }
        return dp[n][k];
    }
};