class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(2, INF));
        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int zero = 0; zero < 2; zero++) {
                if (dp[i][zero] == INF) continue;

                int cur = zero ? 0 : s1[i] - '0';
                int target = s2[i] - '0';

                if (cur == target) {
                    dp[i + 1][0] = min(dp[i + 1][0], dp[i][zero]);
                }

                if (cur == 0 and target == 1) {
                    dp[i + 1][0] = min(dp[i + 1][0], dp[i][zero] + 1);
                }

                if (i + 1 < n) {
                    int cost = 1;

                    if (cur == 0) cost++;
                    if (s1[i + 1] == '0') cost++;

                    if (target == 1) cost++;

                    dp[i + 1][1] = min(dp[i + 1][1], dp[i][zero] + cost);
                }
            }
        }

        return dp[n][0] == INF ? -1 : dp[n][0];
    }
};