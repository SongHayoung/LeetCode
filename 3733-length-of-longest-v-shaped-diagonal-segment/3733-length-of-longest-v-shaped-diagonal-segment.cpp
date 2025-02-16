
int DP[2][500][2][2];
class Solution {
    vector<vector<int>> rotate(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res[j][n-i-1] = A[i][j];
            }
        }
        return res;
    }
    int helper(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size(), res = 0;
        memset(DP,0,sizeof DP);
        for(int i = 0; i < n; i++) {
            memset(DP[!(i&1)], 0, sizeof DP[!(i&1)]);
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 1) {
                    res = max(res, 1);
                    if(i + 1 < n) {
                        if(j + 1 < m and A[i+1][j+1] == 2) DP[!(i&1)][j+1][0][1] = max(DP[!(i&1)][j+1][0][1], 2);
                    }
                }
                if(A[i][j] == 2) {
                    for(int dir = 0; dir < 2; dir++) {
                        for(int dig = 0; dig < 2; dig++) {
                            if(!DP[i&1][j][dig][dir]) continue;
                            res = max(res, DP[i&1][j][dig][dir]);
                            if(i + 1 == n) continue;
                            int nj = j + (dir ? 1 : -1);
                            if(0 <= nj and nj < m and A[i+1][nj] == 0) {
                                DP[!(i&1)][nj][dig][dir] = max(DP[!(i&1)][nj][dig][dir], DP[i&1][j][dig][dir] + 1);
                            }
                            int nnj = j + (dir ? -1 : 1);
                            if(!dig and 0 <= nnj and nnj < m and A[i+1][nnj] == 0) {
                                DP[!(i&1)][nnj][!dig][!dir] = max(DP[!(i&1)][nnj][!dig][!dir], DP[i&1][j][dig][dir] + 1);
                            }
                        }
                    }
                }
                if(A[i][j] == 0) {
                    for(int dir = 0; dir < 2; dir++) {
                        for(int dig = 0; dig < 2; dig++) {
                            if(!DP[i&1][j][dig][dir]) continue;
                            res = max(res, DP[i&1][j][dig][dir]);
                            if(i + 1 == n) continue;
                            int nj = j + (dir ? 1 : -1);
                            if(0 <= nj and nj < m and A[i+1][nj] == 2) {
                                DP[!(i&1)][nj][dig][dir] = max(DP[!(i&1)][nj][dig][dir], DP[i&1][j][dig][dir] + 1);
                            }
                            int nnj = j + (dir ? -1 : 1);
                            if(!dig and 0 <= nnj and nnj < m and A[i+1][nnj] == 2) {
                                DP[!(i&1)][nnj][!dig][!dir] = max(DP[!(i&1)][nnj][!dig][!dir], DP[i&1][j][dig][dir] + 1);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int res = 0;
        for(int i = 0; i < 4; i++) {
            if(res < grid.size()) {
                res = max(res, helper(grid));
            }
            grid = rotate(grid);
        }
        return res;
    }
};
