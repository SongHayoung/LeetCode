class Solution {
    long long dp[222][222];
    long long mod = 1e9 + 7;
    long long helper(string& s, int p, int now) {
        if(p == s.length()) return now == 0;
        if(now < 0) return 0;
        if(now > s.length() - p) return 0;

        if(dp[p][now] != -1) return dp[p][now];
        
        long long& res = dp[p][now] = 0;
        
        if(s[p] == 'D') {
            for(int i = now - 1; i >= 0; i--) {
                res = (res + helper(s,p+1,i)) % mod;
            }
        } else {
            for(int i = now; i <= s.length() - p; i++) {
                res = (res + helper(s,p+1,i)) % mod;
            }
        }
        return res;
    }
public:
    int numPermsDISequence(string s) {
        memset(dp,-1,sizeof dp);
        long long res = 0;
        for(int i = 0; i <= s.length(); i++) {
            res = (res + helper(s, 0, i)) % mod;
        }
        return res;
    }
};