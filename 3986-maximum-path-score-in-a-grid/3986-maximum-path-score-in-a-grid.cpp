class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int>(k+1, INT_MIN)));
        dp[0][0][0] = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) for(int turn = 0; turn <= k; turn++) {
            if(i + 1 < n) {
                int nextTurn = turn + (!!grid[i+1][j]);
                if(nextTurn <= k) {
                    dp[i+1][j][nextTurn] = max(dp[i+1][j][nextTurn], dp[i][j][turn] + grid[i+1][j]);
                }
            }
            if(j + 1 < m) {
                int nextTurn = turn + (!!grid[i][j+1]);
                if(nextTurn <= k) {
                    dp[i][j+1][nextTurn] = max(dp[i][j+1][nextTurn], dp[i][j][turn] + grid[i][j+1]);
                }
            }
        }
        int res = -1;
        for(int turn = 0; turn <= k; turn++) res = max(res, dp[n-1][m-1][turn]);
        return res;
    }
};