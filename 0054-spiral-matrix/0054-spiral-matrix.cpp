class Solution {
    const int visit = -101;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    
    int getNextDir(int y, int x, int n, int m, vector<vector<int>>& matrix, int dir) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        if(0 <= nx && nx < m && 0 <= ny && ny < n && matrix[ny][nx] != visit) return dir;
        return (dir + 1) % 4;
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int y = 0, x = 0, idx = 0, dir = 1;
        vector<int> res(n * m);
        while(idx < n * m) {
            res[idx++] = matrix[y][x];
            matrix[y][x] = visit;
            dir = getNextDir(y, x, n, m, matrix, dir);
            y += dy[dir];
            x += dx[dir];
        }

        return res;
    }
};