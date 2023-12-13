class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> r(n), c(m);
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            r[i] += mat[i][j];
            c[j] += mat[i][j];
        }
        int res = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            res += (r[i] == 1 and c[j] == 1 and mat[i][j] == 1);
        }
        return res;
    }
};