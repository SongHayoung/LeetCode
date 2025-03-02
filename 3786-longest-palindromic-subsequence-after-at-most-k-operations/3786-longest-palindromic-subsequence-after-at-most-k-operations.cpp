int dp[202][202][202];
class Solution {
    int helper(string& s, int op, int l, int r) {
        if(l > r) return 0;
        if(dp[op][l][r] != -1) return dp[op][l][r];
        int& res = dp[op][l][r] = max(helper(s,op,l+1,r), helper(s,op,l,r-1));
        int x = abs(s[l] - s[r]), req = min(x, 26 - x);
        if(op >= req) res = max(res, 1 + (l != r) + helper(s,op - req, l + 1, r - 1));
        return res;
    }
public:
    int longestPalindromicSubsequence(string s, int k) {
        memset(dp,-1,sizeof dp);
        return helper(s, k, 0, s.size() - 1);
    }
};
