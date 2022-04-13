class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for(int y1 = 0; y1 < n; y1++) {
            for(int y2 = y1 + 1; y2 < n; y2++) {
                int count = 0;
                for(int x = 0; x < m; x++) {
                    if(grid[y1][x] and grid[y2][x]) count++;
                }
                res += count * (count - 1) / 2;
            }
        }
        return res;
    }
};