class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int x = 0; x < n; x++) {
            vector<int> r,c;
            for(int i = x, j = 0; i < n and j < n; i++,j++) {
                r.push_back(grid[i][j]);
            }
            for(int i = 0, j = x; i < n and j < n; i++,j++) {
                c.push_back(grid[i][j]);
            }
            
            sort(rbegin(r), rend(r));
            sort(begin(c), end(c));
            
            for(int i = 0, j = x; i < n and j < n; i++,j++) {
                grid[i][j] = c[i];
            }
            for(int i = x, j = 0; i < n and j < n; i++,j++) {
                grid[i][j] = r[j];
            }
            
        }
        return grid;
    }
};