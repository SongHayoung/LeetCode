
class Solution {
public:
    int countCoprime(vector<vector<int>>& mat) {
        long long dp[151]{0,}, dpp[151]{0,}, mod = 1e9 + 7;
        vector<pair<long long, long long>> freq(151);
        auto udt = [&](int row, int val) {
            if(freq[val].first != row) freq[val] = {row,0};
            freq[val].second++;
        };
        for(auto& v : mat[0]) dp[v]++;
        for(int row = 1; row < mat.size(); row++) {
            for(auto& v : mat[row]) udt(row,v);
            for(int i = 1; i <= 150; i++) {
                if(dp[i] == 0) continue;
                for(int j = 1; j <= 150; j++) {
                    if(freq[j].first != row) continue;
                    int g = __gcd(i,j);
                    dpp[g] = (dpp[g] + freq[j].second * dp[i]) % mod;
                }
            }
            swap(dp,dpp);
            memset(dpp,0,sizeof dpp);
        }
        return dp[1];
    }
};

