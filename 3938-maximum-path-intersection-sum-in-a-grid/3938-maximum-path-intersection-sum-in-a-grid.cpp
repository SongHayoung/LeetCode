

class Solution {
    int helper(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size(), res = INT_MIN;
        if(m != 1) res = max({res, A[0][0] + A[0][1], A[0][m-1] + A[0][m-2], A[n-1][0] + A[n-1][1], A[n-1][m-1] + A[n-1][m-2]});
        if(n != 1) res = max({res, A[0][0] + A[1][0], A[0][m-1] + A[1][m-1], A[n-1][0] + A[n-2][0], A[n-1][m-1] + A[n-2][m-1]});
        for(int i = 0; i < n; i++) {
            vector<int> mi(m, INT_MIN);
            mi[0] = 0;
            for(int j = 0, pre = 0; j < m; j++) {
                pre += A[i][j];
                int lookup = j;
                if(i == 0 or i == n - 1 or j == 0 or j == m - 1) {
                    lookup--;
                }
                if(0 <= lookup and lookup < m) res = max(res, pre - mi[lookup]);
                if(j + 1 < m) mi[j+1] = min(mi[j], pre);
            }
        }
        return res;
    }
    void rotate(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> tmp(m, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                tmp[j][n - 1 - i] = grid[i][j];
            }
        }
        grid = move(tmp);
    }
public:
    int maxScore(vector<vector<int>>& grid) {
        int res = INT_MIN;
        for(int i = 0; i < 2; i++) {
            res = max(res, helper(grid));
            rotate(grid);
        }
        return res;
    }
};