class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int MOD = 1000000007;
        
        // memo tables for next cell in each direction
        vector<vector<pair<int,int>>> nxtR(m, vector<pair<int,int>>(n, {INT_MAX, INT_MAX}));
        vector<vector<pair<int,int>>> nxtD(m, vector<pair<int,int>>(n, {INT_MAX, INT_MAX}));
        
        // returns the next empty cell when moving from (i,j) in direction d:
        // d==0 → right, d==1 → down, with cascaded reflections
        function<pair<int,int>(int,int,int)> getNext = [&](int i, int j, int d) -> pair<int,int> {
            auto &memo = (d == 0 ? nxtR[i][j] : nxtD[i][j]);
            if (memo.first != INT_MAX) return memo;
            
            int ni = (d == 0 ? i : i + 1);
            int nj = (d == 0 ? j + 1 : j);
            pair<int,int> res;
            
            if (ni >= m || nj >= n) {
                // out of bounds → invalid
                res = {-1, -1};
            } else if (grid[ni][nj] == 0) {
                // empty → land here
                res = {ni, nj};
            } else {
                // mirror → reflect and continue from the mirror cell
                res = getNext(ni, nj, d ^ 1);
            }
            
            memo = res;
            return res;
        };
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int ways = dp[i][j];
                if (ways == 0) continue;
                
                // move right (with reflections)
                auto [r1, c1] = getNext(i, j, 0);
                if (r1 >= 0) {
                    dp[r1][c1] = (dp[r1][c1] + ways) % MOD;
                }
                
                // move down (with reflections)
                auto [r2, c2] = getNext(i, j, 1);
                if (r2 >= 0) {
                    dp[r2][c2] = (dp[r2][c2] + ways) % MOD;
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};