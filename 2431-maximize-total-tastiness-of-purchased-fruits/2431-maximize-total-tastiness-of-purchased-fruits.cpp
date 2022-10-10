class Solution {
    int dp[1010][6];
public:
    int maxTastiness(vector<int>& price, vector<int>& tastiness, int maxAmount, int maxCoupons) {
        memset(dp,-1,sizeof dp);
        dp[0][0] = 0;
        int res = 0;
        for(int i = 0; i < price.size(); i++) {
            int p = price[i], t = tastiness[i];
            for(int j = maxCoupons; j >= 0; j--) {
                for(int k = maxAmount; k >= p / 2; k--) {
                    if(k >= p and dp[k-p][j] != -1) dp[k][j] = max(dp[k-p][j] + t, dp[k][j]);
                    if(j and dp[k-(p/2)][j-1] != -1) dp[k][j] = max(dp[k][j], dp[k-(p/2)][j-1] + t);
                    res = max(res, dp[k][j]);
                }
            }
        }
        return res;
    }
};