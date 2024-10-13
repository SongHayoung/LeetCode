
class Solution {
    long long mod = 1e9 + 7;
public:
    int countWinningSequences(string s) {
        vector<vector<long long>> dp(3, vector<long long>(2020));
        if(s[0] == 'R') {
            dp[0][1010] = dp[1][1009] = dp[2][1011] = 1;
        }
        if(s[0] == 'S') {
            dp[1][1010] = dp[2][1009] = dp[0][1011] = 1;
        }
        if(s[0] == 'P') {
            dp[2][1010] = dp[0][1009] = dp[1][1011] = 1;
        }
        for(int i = 1; i < s.length(); i++) {
            vector<vector<long long>> dpp(3, vector<long long>(2020));
            vector<long long> p(3);
            if(s[i] == 'R') p[2] = 1, p[1] = -1;
            if(s[i] == 'S') p[0] = 1, p[2] = -1;
            if(s[i] == 'P') p[1] = 1, p[0] = -1;
            for(int j = 0; j < 2020; j++) {
                for(int x = 0; x < 3; x++) {
                    if(!dp[x][j]) continue;
                    for(int y = 0; y < 3; y++) {
                        if(x == y) continue;
                        long long pp = j + p[y];
                        dpp[y][pp] = (dpp[y][pp] + dp[x][j]) % mod;
                    }
                }
            }
            swap(dp,dpp);
        }
        long long res = 0;
        for(int i =1011; i < 2020; i++) {
            res = (res + dp[0][i] + dp[1][i] + dp[2][i]) % mod;
        }
        return res;
    }
};