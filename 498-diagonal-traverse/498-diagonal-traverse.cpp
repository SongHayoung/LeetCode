class Solution {
    bool hasNext(bool dir, int y, int x, int n, int m) {
        if(dir) y--, x++;
        else y++, x--;
        return 0 <= y && y < n && 0 <= x && x < m;
    }
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int y(0), x(0), n(mat.size()), m(mat[0].size());
        vector<int> res;
        bool dir(true);
        res.reserve(m*n);
        while (y != n - 1 || x != m - 1) {
            res.push_back(mat[y][x]);
            if(hasNext(dir, y, x, n, m)) {
                if(dir) y--, x++;
                else y++, x--;
            } else {
                if((dir && x == m - 1) || (!dir && y != n - 1)) y++;
                else x++;
                dir = !dir;
            }
        }
        res.push_back(mat[y][x]);
        return res;
    }
};