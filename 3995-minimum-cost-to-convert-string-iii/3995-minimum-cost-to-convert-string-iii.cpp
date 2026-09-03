class Solution {
public:
    int minCost(string source, string target, vector<vector<string>>& rules, vector<int>& costs) {
        int n = source.size();
        long long INF = 1e18;
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] == INF) continue;
            if(source[i] == target[i]) dp[i+1] = min(dp[i+1], dp[i]);
            for(int j = 0; j < rules.size(); j++) {
                auto &rule = rules[j];
                string &p = rule[0], &r = rule[1];
                int len = p.length(), cost = costs[j];
                if (i + len > n) continue;
                bool ok = true;
                for (int k = 0; k < len and ok; k++) {
                    if (r[k] != target[i + k]) ok = false;
                    if (p[k] == '*') cost++;
                    else if (p[k] != source[i + k]) ok = false;
                }
                if (ok) dp[i + len] = min(dp[i + len], dp[i] + cost);
            }
        }
        return dp[n] == INF ? -1 : dp[n];
    }
};
    