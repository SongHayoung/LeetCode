class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        vector<vector<int>> counter(n, vector<int>(m, INT_MAX));
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> q;
        q.push({0, 0,0});
        counter[0][0] = 0;
        while(!q.empty()) {
            auto [c, y, x] = q.top(); q.pop();
            if(counter[y][x] != c) continue;
            if(y == n - 1 and x == m - 1) return c;
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m) {
                    if(grid[ny][nx] == 0 and counter[ny][nx] > c) {
                        q.push({c, ny, nx});
                        counter[ny][nx] = c;
                    } else if(grid[ny][nx] == 1 and counter[ny][nx] > c + 1) {
                        q.push({c + 1, ny, nx});
                        counter[ny][nx] = c + 1;
                    }
                }
            }
        }

        return -1;
    }
};