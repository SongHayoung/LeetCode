class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        vector<vector<long long>> dp(op1 + 1, vector<long long>(op2 + 1, INT_MAX));
        dp[0][0] = 0;
        for(auto& x : nums) {
            for(int i = op1; i >= 0; i--) {
                for(int j = op2; j >= 0; j--) {
                    if(i + 1 <= op1) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + (x + 1) / 2);
                    if(j + 1 <= op2 and x >= k) dp[i][j+1] = min(dp[i][j+1], dp[i][j] + x - k);
                    if(i + 1 <= op1 and j + 1 <= op2) {
                        if(x >= k) {
                            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + ((x - k) + 1) / 2);
                        }
                        if((x + 1) / 2 >= k) {
                            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + (x + 1) / 2 - k);
                        }
                    }
                    dp[i][j] += x;
                }
            }
        }
        long long res = INT_MAX;
        for(int i = 0; i <= op1; i++) for(int j = 0; j <= op2; j++) res = min(res, dp[i][j]);
        return res;
    }
};