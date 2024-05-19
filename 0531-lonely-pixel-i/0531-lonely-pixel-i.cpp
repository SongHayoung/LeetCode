class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& A) {
        int n = A.size(), m = A[0].size(), res = 0;
        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 'B') cnt++;
            }
            if(cnt == 1) {
                for(int j = 0; j < m; j++) {
                    if(A[i][j] == 'B') {
                        int cnt = 0;
                        for(int i = 0; i < n and cnt < 2; i++) {
                            if(A[i][j] == 'B') cnt++;
                        }
                        if(cnt == 1) res++;
                        break;
                    }
                }
            }
        }
        return res;
    }
};