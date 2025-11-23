class Solution {
public:
    int maxWeight(vector<int>& weights, int w1, int w2) {
        vector<vector<bool>> dp(w1 + 1, vector<bool>(w2 + 1, false));
        dp[0][0] = true;
        int res = 0;
        for(auto& w : weights) {
            for(int i = w1; i >= 0; i--) {
                for(int j = w2; j >= 0; j--) {
                    if(i >= w and dp[i-w][j]) dp[i][j] = true, res = max(res, i + j);
                    if(j >= w and dp[i][j-w]) dp[i][j] = true, res = max(res, i + j);
                }
            }
        }
        return res;
    }
};