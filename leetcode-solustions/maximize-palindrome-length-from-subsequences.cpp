class Solution {
public:
    int longestPalindrome(string w1, string w2) {
        int separate = w1.length();
        w1 += w2;
        vector<vector<int>> dp(w1.length() + 1, vector<int>(w1.length() + 1, 0));
        int res = 0;
        for (int len = 1; len <= w1.size(); ++len)
            for (auto i = 0; i + len <= w1.size(); ++i) {
                if(w1[i] == w1[i + len - 1]) {
                    dp[i][i + len] = dp[i + 1][i + len - 1] + (len == 1 ? 1 : 2);
                    if(i + len - 1 >= separate && i < separate){
                        res = max(res, dp[i][i + len]);
                    }
                } else {
                    dp[i][i + len] = max(dp[i][i + len - 1], dp[i + 1][i + len]);
                }
            }
        return res;
    }
};
