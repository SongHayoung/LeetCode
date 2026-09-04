class Solution {
public:
    vector<string> createGrid(int n, int m) {
        vector<string> res(n, string(m,'#'));
        for(int i = 0; i < n; i++) res[i][0] = '.';
        for(int i = 0; i < m; i++) res[n-1][i] = '.';
        return res;
    }
};