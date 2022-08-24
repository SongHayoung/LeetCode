class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int r1 = 0, r2 = 0, n = colsum.size();
        vector<vector<int>> res(2, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            if(colsum[i] == 2) {
                res[0][i] = res[1][i] = 1;
                r1 += 1;
                r2 += 1;
            }
        }
        for(int i = 0; i < n; i++) {
            if(colsum[i] == 1) {
                if(r1 < upper) {
                    res[0][i] = 1;
                    r1 += 1;
                } else {
                    res[1][i] = 1;
                    r2 += 1;
                }
            }
        }
        if(r1 != upper or r2 != lower) return {};
        return res;
    }
};