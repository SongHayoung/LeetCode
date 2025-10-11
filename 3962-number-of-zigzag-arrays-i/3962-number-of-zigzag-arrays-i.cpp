
long long dp[2][2][2020];
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        vector<int> lo(r + 1), hi(r + 1);
        for(int i = l; i <= r; i++) {
            lo[i] = i - l;
            hi[i] = r - i;
            dp[0][0][i] = dp[0][1][i] = 1;
        }
        long long mod = 1e9 + 7;
        for(int i = 1; i < n; i++) {
            long long loSum = 0, fl = i & 1, nfl = !fl;
            for(int j = l; j <= r; j++) {
                dp[fl][1][j] = loSum;
                loSum = (loSum + dp[nfl][0][j]) % mod;
            }
            long long hiSum = 0;
            for(int j = r; j >= l; j--) {
                dp[fl][0][j] = hiSum;
                hiSum = (hiSum + dp[nfl][1][j]) % mod;
            }
        }
        long long res = 0;
        for(int i = l; i <= r; i++) {
            res = (res + dp[!(n&1)][0][i] + dp[!(n&1)][1][i]) % mod;
        }
        return res;
    }
};