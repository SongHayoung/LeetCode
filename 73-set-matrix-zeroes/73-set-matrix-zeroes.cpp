class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool zeroCol0 = false;
        for(int i = 0; i < n; i++) {
            zeroCol0 |= !matrix[i][0];
            for(int j = 1; j < m; j++)
                if(!matrix[i][j])
                    matrix[i][0] = matrix[0][j] = 0;
        }
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 1; j--) {
                if(!matrix[i][0] || !matrix[0][j]) matrix[i][j] = 0;
            }
        }
        if(zeroCol0) {
            for(int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
    }
};