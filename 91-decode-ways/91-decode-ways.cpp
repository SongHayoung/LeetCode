class Solution {
    int dp[101];
    int dfs(string& s, int pos) {
        if(s.length() <= pos) return 1;
        if(dp[pos] != -1) return dp[pos];
        if(s[pos] == '0') return dp[pos] = 0;
        dp[pos] = dfs(s, pos + 1);
        if(pos + 1 != s.length()) {
            int sum = (s[pos]&0b1111)*10 + (s[pos+1]&0b1111);
            if(1 <= sum and sum <= 26)
                dp[pos] += dfs(s, pos + 2);
        }
        return dp[pos];
    }
public:
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return dfs(s, 0);
    }
};