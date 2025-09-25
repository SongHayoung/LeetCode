class Solution {
public:
    int minimumTotal(vector<vector<int>>& dp) {
        for(int i = 1; i < dp.size(); i++) {
            dp[i][0] += dp[i-1][0];
            dp[i].back() += dp[i-1].back();
            for(int j = 1; j < dp[i].size() - 1; j++) {
                dp[i][j] += min(dp[i-1][j-1], dp[i-1][j]);
            }
        }
        
        return *min_element(begin(dp.back()), end(dp.back()));
    }
};