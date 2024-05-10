class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& A) {
        int n = A.size(), m = A[0].size();
        vector<int> r(n), c(m);
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(A[i][j] == 'B') r[i]++,c[j]++;
        }
        int res = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(A[i][j] == 'B') {
                if(r[i] == 1 and c[j] == 1) res++;
            }
        }
        return res;
    }
};