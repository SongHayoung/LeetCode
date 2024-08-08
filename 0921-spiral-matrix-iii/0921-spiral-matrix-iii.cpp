class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int len = 1, rep = 2, cur = 1;
        vector<vector<int>> res;
        int y = rStart, x = cStart;
        int dy[4]{-1,0,1,0},dx[4]{0,1,0,-1},d=1;
        while(res.size() < rows*cols) {
            if(0 <= y and y < rows and 0 <= x and x < cols) {
                res.push_back({y,x});
            }
            y += dy[d], x += dx[d];
            if(--cur == 0) {
                d = (d + 1) % 4;
                if(--rep == 0) {
                    rep = 2;
                    cur = len = len + 1;
                } else cur = len;
            }
        }
        return res;
    }
};