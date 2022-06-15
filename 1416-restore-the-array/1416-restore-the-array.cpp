class Solution {
    int dp[100001], mod = 1e9 + 7;
    int helper(string& s, int p, int k) {
        if(p == s.length()) return 1;
        if(dp[p] != -1) return dp[p];
        if(s[p] == '0') return 0;
        long now = 0;
        int& res = dp[p] = 0;
        for(int i = p; i < s.length(); i++) {
            now = now * 10 + (s[i] - '0');
            if(now > k) break;
            res = (res + helper(s, i + 1, k)) % mod;
        }
        return res;
    }
public:
    int numberOfArrays(string s, int k) {
        memset(dp, -1, sizeof dp);
        return helper(s, 0, k);
    }
};