class Solution {
public:
    int numberOfWays(int n, int m, int k, vector<int>& source, vector<int>& dest) {
        long long mod = 1e9 + 7;
        array<long long, 4> dp{1,0,0,0};
        while(k--) {
            array<long long, 4> dpp = dp;
            dp[0] = (dpp[1] * (m - 1) + dpp[2] * (n - 1)) % mod;
            dp[1] = (dpp[1] * (m - 2) + dpp[3] * (n - 1) + dpp[0]) % mod;
            dp[2] = (dpp[2] * (n - 2) + dpp[3] * (m - 1) + dpp[0]) % mod;
            dp[3] = (dpp[3] * (m - 2) + dpp[3] * (n - 2) + dpp[1] + dpp[2]) % mod;
        }
        if(source == dest) return dp[0];
        if(source[0] == dest[0]) return dp[1];
        if(source[1] == dest[1]) return dp[2];
        return dp[3];
    }
};