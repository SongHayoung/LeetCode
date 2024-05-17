class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& A) {
        long long n = A.size(), m = A[0].size(), res = 0;
        vector<long long> c(m), r(n);
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(A[i][j]) c[j]++, r[i]++;
        }
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(A[i][j]) res += (c[j] - 1) * (r[i] - 1);
        }
        return res;
    }
};