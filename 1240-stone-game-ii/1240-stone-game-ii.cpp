class Solution {
    vector<vector<int>> dp;
    int calc(vector<int>& p, int pos, int m) {
        if(pos + 2 * m >= p.size()) return p[pos];
        if(dp[pos][m] != -1) return dp[pos][m];
        for(int i = pos + 1; i <= pos + m * 2; i++) {
            dp[pos][m] = max(dp[pos][m], p[pos] - calc(p, i, max(m, i - pos)));
        }
        return dp[pos][m];
    }
public:
    int stoneGameII(vector<int>& p) {
        dp = vector<vector<int>> (p.size(), vector<int>(p.size(), -1));
        partial_sum(rbegin(p), rend(p), rbegin(p), plus<int>());
        return calc(p, 0, 1);
    }
};