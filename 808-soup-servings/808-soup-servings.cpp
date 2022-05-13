class Solution {
    unordered_map<int, unordered_map<int, double>> dp;
    double helper(int n, int m, double prop) {
        if(n <= 0 and m <= 0) return prop / 2;
        if(m <= 0) return 0;
        if(n <= 0) return prop;
        if(prop < 1e-40) {
            return prop;
        }
        if(dp.count(n) and dp[n].count(m)) return dp[n][m];
        dp[n][m] = 0;
        
        dp[n][m] += helper(n - 100, m, prop / 4);
        dp[n][m] += helper(n - 75, m - 25, prop / 4);
        dp[n][m] += helper(n - 50, m - 50, prop / 4);
        dp[n][m] += helper(n - 25, m - 75, prop / 4);
        
        return dp[n][m];
    }
public:
    double soupServings(int n) {
        return helper(n, n, 1.0);
    }
};