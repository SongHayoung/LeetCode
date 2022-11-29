class Solution {
    int dp[1001][1001];
    int lps(string& s, int l, int r) {
        if(l == r) return 1;
        if(l + 1 == r) return s[l] == s[r] ? 2 : -987654321;
        
        if(dp[l][r] != -1) return dp[l][r];
        dp[l][r] = INT_MAX;
        if(s[l] == s[r])
            dp[l][r] = lps(s,l+1,r-1) + 2;
        else
            dp[l][r] = max(lps(s,l+1,r), lps(s,l,r-1));
        return dp[l][r];
    }
public:
    bool isValidPalindrome(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return s.length() - k <= lps(s,0,s.length() - 1);
    }
};