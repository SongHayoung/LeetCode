class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for(int i = 0, j = n - 1; i < n; i++,j--) {
            if(i != j)
                sum += mat[i][i] + mat[i][j];
            else sum += mat[i][i];
        }
        return sum;
    }
};