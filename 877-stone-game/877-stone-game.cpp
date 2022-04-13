class Solution {
    int dp[501][501];
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        for(int i = 0; i < n; i++) dp[i][i] = piles[i];
        for(int diff = 1; diff < n; diff++) {
            for(int i = 0; i < n - diff; i++) {
                dp[i][i + diff] = max(piles[i] + dp[i + 1][i + diff], piles[i + diff] + dp[i][i + diff - 1]);
            }
        }
        return dp[0][n - 1] > 0;
    }
};