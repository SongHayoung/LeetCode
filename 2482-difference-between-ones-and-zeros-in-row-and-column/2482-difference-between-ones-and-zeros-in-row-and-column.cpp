
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<int> ro(n), rz(n), co(m), cz(m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 0) {
                    rz[i] += 1;
                    cz[j] += 1;
                } else {
                    ro[i] += 1;
                    co[j] += 1;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                A[i][j] = ro[i] + co[j] - rz[i] - cz[j];
            }
        }
        return A;
    }
};