class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int dp[1001][1001];
        for(int i = 1; i <= s1.length(); i++) dp[i][0] = dp[i-1][0] + s1[i-1];
        for(int i = 1; i <= s2.length(); i++) dp[0][i] = dp[0][i-1] + s2[i-1];
        for(int i = 0; i < s1.length(); i++) {
            for(int j = 0; j < s2.length(); j++) {
                if(s1[i] == s2[j]) dp[i+1][j+1] = dp[i][j];
                else dp[i+1][j+1] = min(dp[i][j+1] + s1[i], dp[i+1][j] + s2[j]);
            }
        }
        return dp[s1.length()][s2.length()];
    }
};