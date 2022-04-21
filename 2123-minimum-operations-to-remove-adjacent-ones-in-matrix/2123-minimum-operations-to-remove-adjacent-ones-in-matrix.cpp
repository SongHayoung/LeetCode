class Solution {
    int seen[301][301], match[301][301];
    int dy[4]{-1,1,0,0}, dx[4]{0,0,-1,1};
    int n, m;
    int dfs(vector<vector<int>>& g, int y, int x, int& v) {
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(0 <= ny and ny < n and 0 <= nx and nx < m and g[ny][nx] and seen[ny][nx] != v) {
                seen[ny][nx] = v;
                if(match[ny][nx] == -1 or dfs(g, match[ny][nx] / m, match[ny][nx] % m, v)) {
                    match[ny][nx] = m * y + x;
                    match[y][x] = m * ny + nx;
                    return 1;
                }
            }
        }
        return 0;
    }
public:
    int minimumOperations(vector<vector<int>>& grid) {
        memset(seen, -1, sizeof(seen));
        memset(match, -1, sizeof(match));
        n = grid.size(), m = grid[0].size();
        int res = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] and match[i][j] == -1)
                    res += dfs(grid,i,j,seen[i][j] = i * m + j);
        return res;
    }
};