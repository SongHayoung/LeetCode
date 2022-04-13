class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
        vector<vector<int>> vis(n, vector<int>(m, -1));
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> q;
        q.push({grid[0][0], 0,0});
        vis[0][0] = grid[0][0];
        while(!q.empty()) {
            auto [cost, y, x] = q.top(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and (vis[ny][nx] == -1 or vis[ny][nx] > max(grid[ny][nx], vis[y][x]))) {
                    vis[ny][nx] = max(grid[ny][nx], vis[y][x]);
                    if(ny == n - 1 and nx == m - 1) return vis[ny][nx];
                    q.push({vis[ny][nx], ny, nx});
                }
            }
        }
        return vis[n-1][m-1];
    }
};