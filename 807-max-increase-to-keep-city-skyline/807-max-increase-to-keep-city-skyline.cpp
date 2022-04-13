class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<int> row(r,0), col(c,0);
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }
        int res = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                res += min(row[i], col[j]) - grid[i][j];
            }
        }
        return res;
    }
};