class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<long long> dp(target + 1);
        dp[0] = 1;
        long long mod = 1e9 + 7;
        for(auto t : types) {
            long long c = t[0], m = t[1];
            vector<long long> dpp = dp;
            for(int i = 1; i <= c; i++) {
                for(int j = target - i * m; j >= 0; j--) {
                    dpp[j + i * m] = (dpp[j + i * m] + dp[j]) % mod; 
                }
            }
            swap(dpp, dp);
        }
        return dp[target];
    }
};
