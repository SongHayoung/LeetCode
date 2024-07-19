class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
         int n = matrix.size(), m = matrix[0].size();
         vector<int> r(n,INT_MAX), c(m,INT_MIN);
         for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                r[i] = min(r[i], matrix[i][j]);
                c[j] = max(c[j], matrix[i][j]);
            }
         }
         vector<int> res;
         for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(r[i] == matrix[i][j] and c[j] == matrix[i][j]) res.push_back(matrix[i][j]);
            }
         }
         return res;
    }
};