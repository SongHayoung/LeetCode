class Solution {
public:
    long long maxCoins(vector<int>& lane1, vector<int>& lane2) {
        vector<vector<long long>> dp(2,vector<long long>(3,LLONG_MIN / 10));
        dp[0][0] = 0;
        long long res = LLONG_MIN;
        for(int i = 0; i < lane1.size(); i++) {
            long long l1 = lane1[i], l2 = lane2[i];
            
            dp[0][2] = max(dp[0][2], dp[1][1]) + l1;
            dp[1][1] = max({dp[1][1], 0ll, dp[0][0]}) + l2;
            dp[0][0] = max(dp[0][0], 0ll) + l1;
            
            
            res = max({res, dp[0][2], dp[0][0], dp[1][1]});
        }
        return res;
    }
};