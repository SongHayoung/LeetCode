class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), j = matrix[0].size() - 1;
        for(int i = 0; i < n and matrix[i][0] <= target; i++) {
            while(matrix[i][j] > target) j--;
            if(matrix[i][j] == target) return true;
        }
        return false;
    }
};