class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n(grid.size()), m(grid[0].size()), res(0), cmp((1<<10) - 2), vals[9];
        if(n < 2 or m < 2) return res;
        for(int i = 0; i < n - 2; ++i) {
            for(int j = 0; j < m - 2; ++j) {
                vals[0] = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
                vals[1] = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
                vals[2] = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];
                
                vals[3] = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
                vals[4] = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
                vals[5] = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
                
                vals[6] = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
                vals[7] = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];
                
                vals[8] = (1<<grid[i][j]) | (1<<grid[i][j + 1]) | (1<<grid[i][j + 2]) |
                        (1<<grid[i + 1][j]) | (1<<grid[i + 1][j + 1]) | (1<<grid[i + 1][j + 2]) |
                        (1<<grid[i + 2][j]) | (1<<grid[i + 2][j + 1]) | (1<<grid[i + 2][j + 2]);
                
                if (vals[0] == vals[1] and vals[1] == vals[2] and vals[2] == vals[3] and vals[3] == vals[4] and vals[4] == vals[5] and
                vals[5] == vals[6] and vals[6] == vals[7] and vals[8] == cmp){
                    res++;
                }
            }
        }
        return res;
    }
};