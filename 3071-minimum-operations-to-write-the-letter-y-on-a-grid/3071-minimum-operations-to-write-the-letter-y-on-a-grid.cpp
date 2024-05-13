class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& A) {
        int n = A.size();
        int y = 0, no = 0;
        vector<int> Y(3), N(3);
        for(int i = 0; i < n / 2; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j or j == n - i - 1) {
                    Y[A[i][j]]++;
                    y++;
                } else {
                    N[A[i][j]]++;
                    no++;
                }
            }
        }
        for(int i = n / 2; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j == n / 2) {
                   Y[A[i][j]]++;
                    y++;
                } else {
                    N[A[i][j]]++;
                    no++;
                }
            }
        }
        int res = INT_MAX;
        for(int i = 0; i <= 2; i++) for(int j = 0; j <= 2; j++) {
            if(i == j) continue;
            res = min(res, y - Y[i] + no - N[j]);
        }
        return res;
    }
};