class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& A) {
        bool neg = false;
        long long mi = LLONG_MAX, res = 0, n = A.size(), m = A[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mi = min(mi, 1ll * abs(A[i][j]));
                res += abs(A[i][j]);
                if(A[i][j] < 0) neg = !neg;
            }
        }
        return res + (neg ? -mi * 2 : 0);
    }
};