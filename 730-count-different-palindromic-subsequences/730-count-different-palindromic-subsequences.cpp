class Solution {
    int dp[1001][1001][4];
    int mod = 1e9 + 7;
    int helper(string& s, int l, int r, int k) {
        if(l == r) return s[l] == k + 'a';
        if(l > r) return 0;
        if(dp[l][r][k] != -1) return dp[l][r][k];
        int& res = dp[l][r][k] = 0;
        
        if(s[l] == s[r] and s[l] == (k + 'a')) {
            res = 2; // aa and a ? a
            for(int i = 0; i < 4; i++)
                res = (res + helper(s, l + 1, r - 1, i)) % mod;
        } else {
            res = (res + helper(s, l , r - 1, k)) % mod;
            res = (res + helper(s, l + 1, r, k)) % mod;
            res = (res - helper(s, l + 1, r - 1, k)) % mod;
            res = (res + mod) % mod;
        }
        
        return res;
    }
public:
    int countPalindromicSubsequences(string s) {
        memset(dp,-1,sizeof dp);
        int res = 0;
        for(int i = 0; i < 4; i++)
            res = (res + helper(s, 0, s.length() - 1, i)) % mod;
        return res;
    }
};