class Solution {
public:
    int numberOfCombinations(string s) {
        if(s[0] == '0') return 0;
        long long n = s.length(), res = 0, mod = 1e9 + 7;
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1)), lcp(n+1, vector<long long>(n + 1));
        for(int i = n - 1; i >= 0; i--) for(int j = n - 1; j >= 0; j--) {
            if(s[i] == s[j]) lcp[i][j] = lcp[i+1][j+1] + 1;
        }
        auto chk = [&](int x, int i, int j) {
            int len = lcp[x][i];
            return len >= j + 1 - i or s[x + len] < s[i + len];
        };
        for(int i = 0; i < n; i++) dp[0][i] = 1;
        for(int i = 1; i < n; i++) {
            if(s[i] == '0') continue;
            for(long long j = i, k = i - 1, sum = 0; j < n; j++,k--) {
                dp[i][j] = sum;
                if(k >= 0) {
                    if(s[k] > '0' and chk(k,i,j)) dp[i][j] = (dp[i][j] + dp[k][i-1]) % mod;
                    sum = (sum + dp[k][i-1]) % mod;
                }
            }
        }
        for(int i = 0; i < n; i++) res = (res + dp[i][n-1]) % mod;
        return res;
    }
};