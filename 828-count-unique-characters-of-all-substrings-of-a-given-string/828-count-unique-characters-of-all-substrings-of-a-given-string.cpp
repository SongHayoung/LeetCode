class Solution {
public:
    int uniqueLetterString(string s) {
        int dp[26][2], n = s.length(), res = 0;
        
        memset(dp,-1,sizeof(dp));
        
        for(int i = 0; i < n; i++) {
            int index = s[i] - 'A';
            res += (i - dp[index][1]) * (dp[index][1] - dp[index][0]);
            dp[index][0] = dp[index][1];
            dp[index][1] = i;
        }
        
        for(int i = 0; i < 26; i++) {
            res += (n - dp[i][1]) * (dp[i][1] - dp[i][0]);
        }
        return res;
    }
};