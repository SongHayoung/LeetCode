class Solution {
public:
    int longestRepeatingSubstring(string s) {
        int n = s.length(), res = 0;
        vector<vector<int>> dp(n + 1, vector<int>(n+1));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                if(s[i] == s[j])
                    res = max(res, dp[i+1][j+1] = 1 + dp[i][j]);
        return res;
    }
};