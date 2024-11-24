class Solution {
public:
    long long countSubmatrices(vector<vector<int>>& grid, int k) {
        long long res = 0, n = grid.size(), m = grid[0].size();
        grid.push_back(vector<int>(m,k + 1));
        vector<vector<pair<long long, long long>>> dp(m);
        auto clean = [&](int x) {
            int t = 0;
            for(int i = 0; i < dp[x].size(); i++) {
                int h = dp[x].back().first - dp[x][i].first;
                res += h * (h + 1) / 2 * (dp[x][i].second - t);
                t = dp[x][i].second;
            }
            dp[x] = {};
        };
        for(int i = 0; i <= n; i++) {
            for(long long j = 0, len = 0; j < m; j++) {
                if(grid[i][j] > k) {
                    dp[j].push_back({i,0});
                    clean(j), len = 0;
                } else {
                    if(!j or grid[i][j] <= grid[i][j-1]) len++;
                    else len = 1;
                    int pos = i;
                    while(dp[j].size() and dp[j].back().second > len) {
                        long long h = i - dp[j].back().first;
                        long long w = dp[j].back().second - max(len, j ? dp[j][dp[j].size()-2].second : 0);
                        res += h * (h + 1) / 2 * w;
                        pos = dp[j].back().first;
                        dp[j].pop_back();
                    }
                    if(dp[j].size() == 0 or dp[j].back().second != len) {
                        dp[j].push_back({pos,len});
                    }
                }
            }
        }
        return res;
    }
};