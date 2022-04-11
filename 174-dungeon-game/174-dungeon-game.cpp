class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int n = d.size(), m = d[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        dp[n][m-1] = dp[n-1][m] = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                int hp = min(dp[i+1][j], dp[i][j+1]) - d[i][j];
                dp[i][j] = hp <= 0 ? 1 : hp;
            }
        }
        return dp[0][0];
    }
};