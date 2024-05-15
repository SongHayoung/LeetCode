class Solution {
public:
    int numberOfCleanRooms(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size(), res = 1;
        vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(4, 0)));
        vector<vector<int>> clean(n, vector<int>(m, 0));
        clean[0][0] = true;
        int y = 0, x = 0, dir = 1;
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        while(!vis[y][x][dir]) {
            vis[y][x][dir] = true;
            if(!clean[y][x]) {
                res += 1;
                clean[y][x] = true;
            }
            int ny = y + dy[dir], nx = x + dx[dir];
            if(0 > ny or ny >= n or 0 > nx or nx >= m or A[ny][nx] == 1) {
                dir = (dir + 1) % 4;
            } else {
                y = ny, x = nx;
            }
        }
        return res;
    }
};