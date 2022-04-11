class Solution {
public:
    int minSideJumps(vector<int> &obstacles) {
        int sz = obstacles.size();
        vector<vector<long>> dp(3, vector<long>(sz, INT_MAX));
        dp[1][0] = 0;
        for (int i = 0; i < sz - 1; i++) {
            for(int j = 0; j < 3; j++) {
                if(j == (obstacles[i + 1] - 1)) continue;
                dp[j][i + 1] = dp[j][i];
            }
            if (obstacles[i + 1]) {
                for (int j = 1; j <= 3; j++) {
                    if (j == obstacles[i + 1]) continue;
                    if (j == obstacles[i]) continue;
                    dp[j - 1][i + 1] = min(dp[j - 1][i + 1], (dp[obstacles[i + 1] - 1][i] + 1));
                }
            }
            
        }
        return min(dp[0][sz-1], min(dp[1][sz-1], dp[2][sz-1]));
    }
};
