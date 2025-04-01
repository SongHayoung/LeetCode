class Solution {
    vector<long long> dp;
    long long dfs(vector<vector<int>>& q, int n) {
        if(n >= q.size()) return 0;
        if(dp[n] != -1) return dp[n];
        return dp[n] = max(dfs(q, n + 1), q[n][0] + dfs(q, 1 + n + q[n][1]));
    }
public:
    long long mostPoints(vector<vector<int>>& q) {
        dp = vector<long long>(q.size(), -1);
        return dfs(q, 0);
    }
};
