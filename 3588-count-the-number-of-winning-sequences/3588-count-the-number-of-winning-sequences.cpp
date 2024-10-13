class Solution {
    long long mod = 1e9 + 7;
public:
    int countWinningSequences(string s) {
        vector<unordered_map<long long, long long>> dp(3);
        if(s[0] == 'F') {
            dp[0][0] = dp[1][-1] = dp[2][1] = 1;
        }
        if(s[0] == 'E') {
            dp[1][0] = dp[2][-1] = dp[0][1] = 1;
        }
        if(s[0] == 'W') {
            dp[2][0] = dp[0][-1] = dp[1][1] = 1;
        }
        for(int i = 1; i < s.length(); i++) {
            vector<unordered_map<long long, long long>> dpp(3);
            vector<long long> p(3);
            if(s[i] == 'F') p[2] = 1, p[1] = -1;
            if(s[i] == 'E') p[0] = 1, p[2] = -1;
            if(s[i] == 'W') p[1] = 1, p[0] = -1;
            for(int x = 0; x < 3; x++) {
                for(int y = 0; y < 3; y++) {
                    if(x == y) continue;
                    for(auto& [k,v] : dp[x]) {
                        long long nk = k + p[y];
                        dpp[y][nk] = (dpp[y][nk] + v) % mod;
                    }
                }
            }
            swap(dp,dpp);
        }
        long long res = 0;
        for(int i = 0; i < 3; i++) {
            for(auto& [k,v] : dp[i]) {
                if(k > 0) res = (res + v) % mod;
            }
        }
        return res;
    }
};