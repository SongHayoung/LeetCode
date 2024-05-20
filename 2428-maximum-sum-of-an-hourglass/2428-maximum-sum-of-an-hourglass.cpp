class Solution {
public:
    int maxSum(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        int res = 0;
        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < m - 2; j++) {
                int now = A[i][j] + A[i][j+1] + A[i][j+2] + A[i+1][j+1] + A[i+2][j] + A[i+2][j+1] + A[i+2][j+2];
                res = max(res, now);
            }
        }
        return res;
    }
};
