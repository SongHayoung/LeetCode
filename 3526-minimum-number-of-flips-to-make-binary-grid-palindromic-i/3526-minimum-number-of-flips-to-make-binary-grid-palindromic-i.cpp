class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), r = 0, c = 0;
        for(int i = 0; i < n / 2; i++) {
            for(int j = 0; j < m / 2; j++) {
                if(grid[i][j] != grid[i][m-j-1]) r++;
                if(grid[i][j] != grid[n-i-1][j]) c++;
            }
        }
        for(int i = n / 2; i < n; i++) {
            for(int j = m / 2; j < m; j++) {
                if(grid[i][j] != grid[i][m-j-1]) r++;
                if(grid[i][j] != grid[n-i-1][j]) c++;
            }
        }
        return min(r,c);
    }
};