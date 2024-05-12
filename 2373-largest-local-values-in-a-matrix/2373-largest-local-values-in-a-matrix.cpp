class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n-2, vector<int>(m-2, INT_MIN));
        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < m - 2; j++) {
                for(int k = 0; k < 3; k++) {
                    for(int l = 0; l < 3; l++) {
                        res[i][j] = max(res[i][j], grid[i+k][j+l]);
                    }
                }
            }
        }
        return res;
    }
};
