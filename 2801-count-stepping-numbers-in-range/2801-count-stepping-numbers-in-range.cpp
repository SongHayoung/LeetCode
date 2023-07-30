class Solution {
    long long dp[111][10], sum[111], mod = 1e9 + 7;
    bool stepping(string& s) {
        for(int i = 1; i < s.length(); i++) {
            if(abs(s[i] - s[i-1]) == 1) continue;
            return false;
        }
        return true;
    }
    long long helper(string& s, long long pos) {
        if(pos + 1 >= s.length()) return 1;
        long long res = 0, a = s[pos] - '0', b = s[pos+1] - '0';
        if(a - 1 == b) return helper(s,pos+1);
        if(a - 1 < b and a > 0) res = (res + dp[s.length() - pos - 2][a - 1]) % mod;
        if(a + 1 == b) return (res + helper(s,pos+1)) % mod;
        if(a + 1 < b) res = (res + dp[s.length() - pos - 2][a + 1]) % mod;
        return res;
    }
    long long helper(string& s) {
        if(s.length() == 1) return s[0] - '0';
        long long res = sum[s.length() - 2];
        for(int i = 1; i < s[0] - '0'; i++) res = (res + dp[s.length() - 1][i]) % mod;
        return (res + helper(s,0)) % mod;
    }
public:
    int countSteppingNumbers(string low, string high) {
        memset(dp, 0, sizeof dp);
        memset(sum,0,sizeof sum);
        for(int i = 0; i <= 9; i++) dp[0][i] = 1;
        sum[0] = 9;
        for(int i = 1; i < 111; i++) {
            sum[i] = sum[i-1];
            for(int j = 0; j <= 9; j++) {
                if(0 <= j - 1 and j - 1 <= 9) dp[i][j] += dp[i - 1][j - 1];
                if(0 <= j + 1 and j + 1 <= 9) dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= mod;
                if(j) sum[i] = (sum[i] + dp[i][j]) % mod;
            }
        }
        return (helper(high) - helper(low) + stepping(low) + mod) % mod;
    }
};