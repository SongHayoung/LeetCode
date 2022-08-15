class Solution {
    bool rcheck(vector<vector<int>>& A, int i, int j, int k, int cmp) {
        for(int l = 0; l <= k; l++) {
            int now = A[i-l][j] - (j - k - 1 >= 0 ? A[i-l][j-k-1] : 0);
            if(now != cmp) return false;
        }
        return true;
    }
    bool ccheck(vector<vector<int>>& A, int i, int j, int k, int cmp) {
        for(int l = 0; l <= k; l++) {
            int now = A[i][j-l] - (i - k - 1 >= 0 ? A[i-k-1][j-l] : 0);
            if(now != cmp) return false;
        }
        return true;
    }
    bool dcheck(vector<vector<int>>& A, int i, int j, int k, int cmp) {
        return (A[i][j] - (i > k and j > k ? A[i-k-1][j-k-1] : 0)) == cmp;
    }
    bool ddcheck(vector<vector<int>>& A, int i, int j, int k, int cmp) {
        return (A[i][j-k] - (i > k and j + 1 < A[0].size() ? A[i-k-1][j + 1] : 0)) == cmp;
    }
public:
    int largestMagicSquare(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> rsum(n,vector<int>(m));
        vector<vector<int>> csum(n,vector<int>(m));
        vector<vector<int>> dsum(n,vector<int>(m));
        vector<vector<int>> ddsum(n,vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                rsum[i][j] = A[i][j] + (j ? rsum[i][j-1] : 0);
                csum[i][j] = A[i][j] + (i ? csum[i-1][j] : 0);
                dsum[i][j] = A[i][j] + (i and j ? dsum[i-1][j-1] : 0);
                ddsum[i][j] = A[i][j] + (i and j + 1 < m ? ddsum[i-1][j+1] : 0);
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = 0; k <= min(i,j); k++) {
                    int now = rsum[i][j] - (j-k-1 >= 0 ? rsum[i][j-k-1] : 0);
                    if(rcheck(rsum, i, j, k, now) and ccheck(csum, i, j, k, now) and dcheck(dsum, i, j, k, now) and ddcheck(ddsum, i, j, k, now)) res = max(res, k + 1);
                }
            }
        }
        return res;
    }
};