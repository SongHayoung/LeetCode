class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& A) {
        int n = A.size(), m = A[0].size(), res = 0;
        vector<int> row(n), col(m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 'B') {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 'B' and row[i] == 1 and col[j] == 1) res++;
            }
        }
        return res;
    }
};