class Solution {
    pair<int, int> start, end;
    int route = 2, n, m;
    vector<vector<bool>> v;
    int dx[4]{0,1,0,-1}, dy[4]{-1,0,1,0};
    int dfs(int y, int x, int path) {
        if(y == end.first && x == end.second) return path == route;
        v[y][x] = true;
        int res(0);
        for(int i = 0; i < 4; i++) {
            int ny(y + dy[i]), nx(x + dx[i]);
            if(0 <= ny && ny < n && 0 <= nx && nx < m && !v[ny][nx]) {
                res += dfs(ny, nx, path + 1);
            }
        }
        v[y][x] = false;
        return res;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size(), v = vector<vector<bool>>(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) start = {i, j};
                else if(grid[i][j] == 2) end = {i, j};
                else if(!grid[i][j]) route++;
                else v[i][j] = true;
            }
        }

        return dfs(start.first, start.second, 1);
    }
};