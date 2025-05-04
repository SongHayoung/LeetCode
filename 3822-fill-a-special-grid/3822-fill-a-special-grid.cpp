class Solution {
public:
    vector<vector<int>> specialGrid(int N) {
        int size = 1 << N;
        vector<vector<int>> res(size, vector<int>(size, 0));
        int table[2][2] {{3, 0}, {2, 1}};
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for(int k = N - 1; k >= 0; k--) {
                    res[i][j] = (res[i][j]<<2) + table[(i >> k) & 1][(j >> k) & 1];
                }
            }
        }
        return res;
    }
};