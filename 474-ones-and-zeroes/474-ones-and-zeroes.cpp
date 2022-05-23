class Solution {
    int dp[101][101];
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int res = 0;
        memset(dp, 0, sizeof dp);
        for(auto& str : strs) {
            int zero = 0, one = 0;
            for(auto& ch : str) {
                if(ch == '0') zero++;
                else one++;
            }
            if(zero > m or one > n) continue;
            for(int i = m - zero; i >= 0; i--) {
                for(int j = n - one; j >= 0; j--) {
                    dp[i+zero][j+one] = max(dp[i+zero][j+one], 1 + dp[i][j]);
                    res = max(res, dp[i+zero][j+one]);
                }
            }
            
            dp[zero][one] = max(dp[zero][one], 1);
            res = max(res, dp[zero][one]);
        }
        return res;
    }
};