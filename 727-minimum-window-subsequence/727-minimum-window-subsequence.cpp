class Solution {
    int dp[20001][101];
public:
    string minWindow(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        int minimumLength = INT_MAX, endAt = INT_MAX;
        for(int i = 1; i <= m; i++) dp[0][i] = INT_MIN;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i-1] == s2[j-1]) {
                    int upperMin = min(dp[i-1][j-1] < 0 ? INT_MAX : dp[i-1][j-1], dp[i-1][j] < 0 ? INT_MAX : dp[i-1][j]);
                    dp[i][j] = (upperMin == INT_MAX ? INT_MIN : upperMin + 1); 
                } else {
                    dp[i][j] = dp[i-1][j] + 1;
                }
            }
            if(dp[i][m] >= m and dp[i][m] < minimumLength) {
                minimumLength = dp[i][m];
                endAt = i;
            }
        }
        
        return minimumLength == INT_MAX ? "" : s1.substr(endAt - minimumLength, minimumLength);
    }
};