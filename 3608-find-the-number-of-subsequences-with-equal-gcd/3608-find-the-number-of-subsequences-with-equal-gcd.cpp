class Solution {
    long long mod = 1e9 + 7;
public:
    int subsequencePairCount(vector<int>& nums) {
        int ma = *max_element(begin(nums), end(nums)) + 1;
        vector<vector<long long>> dp(ma, vector<long long>(ma));
        for(auto& n : nums) {
            vector<vector<long long>> dpp(ma, vector<long long>(ma));
            for(int f = 0; f < dp.size(); f++) {
                for(int s = 0; s < dp.size(); s++) {
                    if(!dp[f][s]) continue;
                    dpp[f][s] = (dpp[f][s] + dp[f][s]) % mod;
                    long long fg = __gcd(f,n), sg = __gcd(s,n), c = dp[f][s];
                    dpp[fg][s] = (dpp[fg][s] + c) % mod;
                    dpp[f][sg] = (dpp[f][sg] + c) % mod;
                }
            }
            dpp[n][0] = (dpp[n][0] + 1) % mod;
            dpp[0][n] = (dpp[0][n] + 1) % mod;
            swap(dp,dpp);
        }
        long long res = 0;
        for(int i = 1; i < dp.size(); i++) res = (res + dp[i][i]) % mod;
        return res;
    }
};