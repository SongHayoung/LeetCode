class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n = mat1.size(), m = mat2[0].size(), o = mat2.size();
        vector<vector<int>> ma(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k < o; k++)
                    ma[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
        return ma;
    }
};