class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i = x, j = x + k - 1; i < j; i++,j--) {
            for(int pos = y; pos < y + k; pos++) {
                swap(grid[i][pos], grid[j][pos]);
            }
        }
        return grid;
    }
};