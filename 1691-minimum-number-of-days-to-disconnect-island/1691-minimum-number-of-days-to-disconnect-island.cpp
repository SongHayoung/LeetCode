class Solution {
    bool bfs(vector<vector<int>> g, int sy, int sx, int islands) {
        if(g[sy][sx] == 0) return true;
        int n = g.size(), m = g[0].size();
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({sy,sx});
        g[sy][sx] = 0;
        islands--;
        while(!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and g[ny][nx]) {
                    g[ny][nx] = 0;
                    q.push({ny,nx});
                    islands--;
                }
            }
        }
        
        return islands;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<pair<int,int>> islands;
        int res = 2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    islands.push_back({i,j});
                }
            }
        }
        if(islands.size() == 1) return 1;
        if(islands.empty() or bfs(grid,islands[0].first, islands[0].second, islands.size())) return 0;
        int sy = islands.back().first, sx = islands.back().second;
        for(auto [y, x] : islands) {
            grid[y][x] = 0;
            if(bfs(grid, sy, sx, islands.size() - 1)) return 1;
            sy = y, sx = x;
            grid[y][x] = 1;
        }
        
        return 2;
    }
};