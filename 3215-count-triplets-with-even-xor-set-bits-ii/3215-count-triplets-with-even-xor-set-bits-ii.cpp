class Solution {
public:
    long long tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
        vector<vector<long long>> dp(3,vector<long long>(2));
        for(auto& n : a) dp[0][__builtin_popcount(n) & 1]++;
        for(auto& n : b) dp[1][__builtin_popcount(n) & 1]++;
        for(auto& n : c) dp[2][__builtin_popcount(n) & 1]++;
        long long res = 0;
        for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) {
            if((i + j + k) & 1) continue;
            res += dp[0][i] * dp[1][j] * dp[2][k];
        }
        return res;
    }
};