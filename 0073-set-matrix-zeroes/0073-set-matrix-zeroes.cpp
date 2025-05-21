class Solution {
public:
    void setZeroes(vector<vector<int>>& A) {
        bool r = 0, c = 0;
        int n = A.size(), m = A[0].size();
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(A[i][j]) continue;
            if(i == 0 and j == 0) r = c = 1;
            if(j == 0) c = 1;
            if(i == 0) r = 1;
            A[i][0] = A[0][j] = 0;
        }
        for(int j = m - 1; j > 0; j--) {
            if(A[0][j]) continue;
            for(int i = 1; i < n; i++) A[i][j] = 0;
        }
        for(int i = n - 1; i > 0; i--) {
            if(A[i][0]) continue;
            for(int j = 1; j < m; j++) A[i][j] = 0;
        }
        if(c)
            for(int i = 1; i < n; i++) A[i][0] = 0;
        if(r)
            for(int j = 1; j < m; j++) A[0][j] = 0;
    }
};