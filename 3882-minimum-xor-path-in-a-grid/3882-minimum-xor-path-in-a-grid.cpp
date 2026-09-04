class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        unordered_set<int> dp[n][m];
        dp[0][0].insert(grid[0][0]);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i) {
                    for(auto& x : dp[i-1][j]) dp[i][j].insert(x ^ grid[i][j]);
                }
                if(j) {
                    for(auto& x : dp[i][j-1]) dp[i][j].insert(x ^ grid[i][j]);
                }
            }
        }
        return *min_element(begin(dp[n-1][m-1]), end(dp[n-1][m-1]));
    }
};