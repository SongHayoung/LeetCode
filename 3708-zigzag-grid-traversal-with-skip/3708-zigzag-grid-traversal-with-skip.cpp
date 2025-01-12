class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), idx = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i & 1 ? m & 1 ? m - 2 : m - 1 : 0; 0 <= j and j < m; j += (i & 1 ? -2 : 2)) {
                if(grid[0].size() == idx) grid[0].push_back(0);
                grid[0][idx++] = grid[i][j];
            }
        }
        return grid[0];
    }
};