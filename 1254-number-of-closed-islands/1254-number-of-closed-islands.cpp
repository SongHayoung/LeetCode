class Solution {
    int floodfill(vector<vector<int>>& grid, int y, int x) {
        if(0 <= y and y < grid.size() and 0 <= x and x < grid[y].size() and grid[y][x] == 0) {
            return (grid[y][x] = 1) + floodfill(grid, y - 1, x) + floodfill(grid, y + 1, x) + floodfill(grid, y, x + 1) + floodfill(grid, y , x - 1);
        }
        return 0;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < m; i++) {
            if(!grid[0][i]) floodfill(grid, 0, i);
            if(!grid[n-1][i]) floodfill(grid, n-1, i);
        }
        for(int i = 0; i < n; i++) {
            if(!grid[i][0]) floodfill(grid,i,0);
            if(!grid[i][m-1]) floodfill(grid,i,m-1);
        }
        
        int res = 0;
        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j < m - 1; j++) {
                if(!grid[i][j]) {
                    floodfill(grid,i,j);
                    res++;
                }
            }
        }
        
        return res;
    }
};