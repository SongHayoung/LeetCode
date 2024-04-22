class Solution {
public:
    bool searchMatrix(vector<vector<int>>& A, int target) {
        int n = A.size(), m = A[0].size();
        int l = 0, r = n * m - 1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int y = mid / m, x = mid % m;
            if(A[y][x] == target) return true;
            else if(A[y][x] < target) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};