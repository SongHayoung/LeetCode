class Solution {
public:
    int countBattleships(vector<vector<char>>& A) {
        int n = A.size(), m = A[0].size(), res = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(A[i][j] == '.') continue;
            res++;
            int d = i + 1, r = j + 1;
            while(d < n and A[d][j] == 'X') {
                A[d][j] = '.'; d++;
            }
            while(r < m and A[i][r] == 'X') {
                A[i][r] = '.'; r++;
            }
        }
        return res;
    }
};