
class Solution {
    int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
    long long bfs(vector<vector<int>>& mat, vector<vector<int>>& vis, int n, int m, int y, int x, int id) {
        long long res = 0;
        queue<pair<int, int>> q;
        auto push = [&](int y, int x) {
            if(vis[y][x] == 0) {
                vis[y][x] = id;
                res += mat[y][x];
                q.push({y,x});
            }
        };
        push(y,x);
        while(q.size()) {
            auto [y,x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and mat[ny][nx] != -1 and vis[ny][nx] == 0) push(ny,nx);
            }
        }
        return res;
    }
public:
    long long sumRemoteness(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        vector<long long> sums{0};
        long long res = 0, tot = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(grid[i][j] == -1) continue;
            long long now = bfs(grid,vis,n,m,i,j,sums.size());
            sums.push_back(now);
            tot += now;
        }
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(grid[i][j] == -1) continue;
            res += tot - sums[vis[i][j]];
        }
        return res;
    }
};