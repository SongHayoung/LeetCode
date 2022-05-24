class Solution {
public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        int n = coins.size();
        if(n == 1) return {1};
        vector<int> dp(n, INT_MAX);
        vector<int> path(n, -1);
        dp[n-1] = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(coins[i] == -1) continue;
            for(int j = i + 1; j < min(n, i + maxJump + 1); j++) {
                if(dp[j] == INT_MAX) continue;
                if(dp[j] + coins[j] < dp[i]) {
                    dp[i] = dp[j] + coins[j];
                    path[i] = j;
                }
            }
        }
        
        if(path[0] == -1 or coins[n-1] == -1) return {};
        vector<int> res;
        int p = 0;
        while(p != -1) {
            res.push_back(p + 1);
            p = path[p];
        }
        return res;
    }
};