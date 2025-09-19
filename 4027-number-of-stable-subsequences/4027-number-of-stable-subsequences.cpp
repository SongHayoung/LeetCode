class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        long long dp[2][3] {{0,0,0},{0,0,0}};
        long long mod = 1e9 + 7;
        for(auto& n : nums) {
            int p = n & 1;
            dp[p][2] = (dp[p][2] + dp[p][1]) % mod;
            dp[p][1] = (dp[p][1] + dp[!p][1] + dp[!p][2] + 1) % mod;
        }
        return (dp[0][1] + dp[0][2] + dp[1][1] + dp[1][2]) % mod;
    }
};
