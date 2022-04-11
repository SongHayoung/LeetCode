class Solution {
    int n, m;
    vector<vector<int>> dis;
    vector<vector<int>> visCount;
    void bfs(vector<vector<int>>& grid, int sy, int sx) {
        int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0}, distance = 1;
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        vis[sy][sx] = true;
        queue<pair<int, int>> q;
        q.push({sy,sx});
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [y, x] = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(0 <= ny and ny < n and 0 <= nx and nx < m and grid[ny][nx] == 0 and !vis[ny][nx]) {
                        q.push({ny,nx});
                        vis[ny][nx] = true;
                        visCount[ny][nx]++;
                        dis[ny][nx] += distance;
                    }
                }
            }
            distance++;
        }
    }
    
public:
    int shortestDistance(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        dis = vector<vector<int>>(n, vector<int>(m,0));
        visCount = vector<vector<int>>(n, vector<int>(m,0));
        int buildings = 0;
        queue<array<int,3>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    bfs(grid,i,j);
                    buildings++;
                }
            }
        }
        
        int res = INT_MAX;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(visCount[i][j] == buildings) {
                    res = min(res, dis[i][j]);
                }
        return res == INT_MAX ? - 1 : res;
    }
};