class Solution {
    vector<vector<bool>> visited;
    int bfs(vector<vector<int>>& grid, int sy, int sx) {
        if(visited[sy][sx]) return 0;
        int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
        queue<pair<int, int>> q;
        q.push({sy,sx});
        
        visited[sy][sx] = true;
        int cnt = 0;
        while(!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < grid.size() and 0 <= nx and nx < grid[0].size() and grid[ny][nx] == 1 and !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    cnt++;
                    q.push({ny,nx});
                }
            }
        }
        return cnt;
    }
    bool nearConnected(int y, int x) {
        if(0 <= y and y < visited.size() and 0 <= x and x < visited[0].size()) {
            return visited[y][x];
        }
        return false;
    }
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int sz = hits.size(), n = grid.size(), m = grid[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m,false));
        vector<int> res(sz);
        for(int i = 0; i < sz; i++) {
            if(grid[hits[i][0]][hits[i][1]] == 0) {
                hits[i][0] = hits[i][1] = -1;
            } else {
                grid[hits[i][0]][hits[i][1]] = 0;
            }
        }
        for(int i = 0; i < m; i++) {
            if(grid[0][i])
                bfs(grid,0,i);
        }
        for(int i = sz - 1; i >= 0; i--) {
            if(hits[i][0] == -1) continue;
            grid[hits[i][0]][hits[i][1]] = 1;
            if(nearConnected(hits[i][0] - 1, hits[i][1]) or
               nearConnected(hits[i][0] + 1, hits[i][1]) or
               nearConnected(hits[i][0], hits[i][1] - 1) or
               nearConnected(hits[i][0], hits[i][1] + 1) or
               hits[i][0] == 0
              ) {
                res[i] = bfs(grid, hits[i][0], hits[i][1]);
            }
        }
        
        return res;
    }
};