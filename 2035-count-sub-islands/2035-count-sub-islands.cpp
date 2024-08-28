class Solution {
    int floodfill(vector<vector<int>>& g1, vector<vector<int>>& g2, int y, int x) {
        int res = 0;
        if(0 <= y and y < g1.size() and 0 <= x and x < g1[0].size()) {
            if(g1[y][x] and g2[y][x]) {
                g1[y][x] = g2[y][x] = 0;
                res += 1;
                res += floodfill(g1,g2,y+1,x);
                res += floodfill(g1,g2,y-1,x);
                res += floodfill(g1,g2,y,x+1);
                res += floodfill(g1,g2,y,x-1);
            } else if(g2[y][x]) res = -250000;         
        }
        return res;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int res = 0;
        int n = grid1.size(), m = grid1[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                res += (floodfill(grid1,grid2,i,j) > 0);
            }
        return res;
    }
};