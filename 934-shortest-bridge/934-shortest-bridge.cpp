class Solution {
    queue<pair<int,int>> q;
    int dx[4]{0,1,0,-1}, dy[4]{-1,0,1,0};
    void bfs(vector<vector<int>>& grid, int sy, int sx) {
        queue<pair<int,int>> Q;
        Q.push({sy,sx});
        q.push({sy,sx});
        int n = grid.size(), m = grid[0].size();
        grid[sy][sx] = 2;
        while(!Q.empty()) {
            auto [y, x] = Q.front(); Q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and grid[ny][nx] == 1) {
                    grid[ny][nx] = 2;
                    q.push({ny,nx});
                    Q.push({ny,nx});
                }
            }
        }
    }
    void init(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(g[i][j]) {
                    bfs(g,i,j);
                    return;
                }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        init(grid);
        int res = 0;
        int n = grid.size(), m = grid[0].size();
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [y,x] = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                   int ny = y + dy[i], nx = x + dx[i];
                    if(0 <= ny and ny < n and 0 <= nx and nx < m) {
                        if(grid[ny][nx] == 1) return res;
                        if(grid[ny][nx] == 0) {
                            grid[ny][nx] = 2;
                            q.push({ny,nx});
                        }
                    }
                }
            }
            res++;
        }
        return res;
    }
};