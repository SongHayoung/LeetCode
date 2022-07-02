class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& A) {
        int n = A.size(), m = A[0].size();
        for(int i = 0; i < n; i++) {
            int l = m - 1, r = m - 1,c = 0;
            while(l >= 0) {
                int s = 0;
                while(l >= 0 and A[i][l] != '*') {
                    if(A[i][l--] == '#') s++;
                }
                while(s--) A[i][r--] = '#';
            
                while(r > l) A[i][r--] = '.';
                
                r = l = l - 1;
            }
        }
        vector<vector<char>> res(m, vector<char>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                res[i][j] = A[n-j-1][i];
            }
        }
        return res;
    }
};