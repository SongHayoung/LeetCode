class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int res = 0, n = grid.size(), m = grid[0].size();
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int x = max(grid[i-1][j] + 1, grid[i][j]);
                res += x - grid[i][j];
                grid[i][j] = x;
            }
        }
        return res;
    }
};