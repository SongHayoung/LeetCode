class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        if(n == r and m == c) return mat;
        if(n*m != r*c) return mat;
        vector<vector<int>> res(r,vector<int>(c));
        for(int i = 0; i < r * c; i++) {
            int ty = i / c, tx = i % c;
            int oy = i / m, ox = i % m;
            res[ty][tx] = mat[oy][ox];
        }
        return res;
    }
};