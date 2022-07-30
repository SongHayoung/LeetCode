class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<int> A;
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i) matrix[i][j] ^= matrix[i-1][j];
                if(j) matrix[i][j] ^= matrix[i][j-1];
                if(i and j) matrix[i][j] ^= matrix[i-1][j-1];
                A.push_back(matrix[i][j]);
            }
        }
        sort(rbegin(A), rend(A));
        return A[k-1];
    }
};