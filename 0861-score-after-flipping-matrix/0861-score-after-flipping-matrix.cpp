class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        for(auto& row : grid) {
            if(row[0] == 0)
                for(auto& col : row)
                    col = col ? 0 : 1;
        }
        for(int i = 0; i < m; i++) {
            int c = 0;
            for(int j = 0; j < n; j++) {
                if(grid[j][i]) c++;
            }
            c = max(c, n - c);
            res += c<<(m - 1 -i);
        }
        return res;
    }
};