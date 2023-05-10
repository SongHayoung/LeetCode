class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int y = 0, x = 0, dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1}, d = 1;
        for(int i = 1; i <= n * n; i++) {
            res[y][x] = i;
            int ny = y + dy[d], nx = x + dx[d];
            if(0 <= ny and ny < n and 0 <= nx and nx < n and res[ny][nx] == 0) {
                y = ny, x = nx;
            } else {
                d = (d + 1) % 4;
                y += dy[d], x += dx[d];
            }
        }
        return res;
    }
};