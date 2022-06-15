class Solution {
    void helper(vector<vector<int>>& A, int y, int x) {
        int n = A.size(), m = A[0].size();
        vector<int> S;
        for(int i = 0; y + i < n and x + i < m; i++) {
            S.push_back(A[y+i][x+i]);
        }
        sort(begin(S), end(S));
        for(int i = 0; y + i < n and x + i < m; i++) {
            A[y+i][x+i] = S[i];
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < n; i++) {
            helper(mat, i, 0);
        }
        for(int i = 1; i < m; i++) {
            helper(mat, 0, i);
        }
        return mat;
    }
};