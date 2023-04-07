class Solution {
    void floodfill(vector<vector<int>>& g, int y, int x) {
        if(0 <= y and y < g.size() and 0 <= x and x < g[0].size() and g[y][x] == 1) {
            g[y][x] = 0;
            floodfill(g,y+1,x);
            floodfill(g,y-1,x);
            floodfill(g,y,x+1);
            floodfill(g,y,x-1);
        }
        
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            floodfill(grid,i,0);
            floodfill(grid,i,m-1);
        }
        for(int i = 0; i < m; i++) {
            floodfill(grid,0,i);
            floodfill(grid,n-1,i);
        }
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                res += grid[i][j];
        }
        return res;
    }
};