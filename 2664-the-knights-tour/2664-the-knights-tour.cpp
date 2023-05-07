class Solution {
    int dy[8]{-1,-2,-2,-1,1,2,2,1}, dx[8]{-2,-1,1,2,2,1,-1,-2};
    bool helper(vector<vector<int>>& res, int y, int x, int t, int n) {
        res[y][x] = t;
        if(t == n - 1) return true;
        else {
            for(int i = 0; i < 8; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < res.size() and 0 <= nx and nx < res[ny].size() and res[ny][nx] == -1) {
                    if(helper(res,ny,nx,t+1,n)) return true;
                }
            }
            res[y][x] = -1;
            return false;
        }
    }
public:
    vector<vector<int>> tourOfKnight(int n, int m, int r, int c) {
        vector<vector<int>> res(n,vector<int>(m, -1));
        helper(res,r,c,0,n * m);
        return res;
    }
};