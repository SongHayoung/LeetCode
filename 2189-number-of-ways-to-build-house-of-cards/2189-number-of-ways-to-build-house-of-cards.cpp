class Solution {
public:
    int houseOfCards(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;
        for(int i = 2; i <= n; i += 3) {
            for(int j = n; j >= i; j--) {
                dp[j] += dp[j-i];
            }
        }
        return dp[n];
    }
};