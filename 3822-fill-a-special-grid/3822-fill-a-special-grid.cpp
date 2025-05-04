class Solution {
    void dnc(vector<vector<int>>& res, int y, int x, int len, int& ord) {
        if(len == 1) res[y][x] = ord++;
        else {
            len>>=1;
            dnc(res, y, x + len, len, ord);
            dnc(res, y + len, x + len, len, ord);
            dnc(res, y + len, x, len, ord);
            dnc(res, y, x, len, ord);
        }
    }
public:
    vector<vector<int>> specialGrid(int N) {
        int n = 1<<N, ord = 0;
        vector<vector<int>> res(n, vector<int>(n));
        dnc(res, 0,0,n, ord);
        return res;
    }
};