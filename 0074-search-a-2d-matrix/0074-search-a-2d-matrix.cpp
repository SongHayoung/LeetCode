class Solution {
    bool ok(vector<int>& A, int target) {
        int l = 0, r = A.size() - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(A[m] == target) return true;
            else if(A[m] < target) l = m + 1;
            else r = m - 1;
        }
        return false; 
    }
    bool row(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1, res = 0;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(matrix[m].front() <= target and target <= matrix[m].back()) {
                return ok(matrix[m], target);
            } else if(matrix[m].back() < target) {
                l = m + 1;
            } else r = m - 1;
        }
        return res;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return row(matrix, target);
    }
};