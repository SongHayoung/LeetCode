class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int res = 0, n = grid.size(), m = grid[0].size();
        int dy[4]{0,1,0,-1}, dx[4]{1,0,-1,0};
        auto bfs = [&](int y, int x) {
            int res = 0;
            queue<pair<int,int>> q;
            auto push = [&](int y, int x) {
                if(grid[y][x]) {
                    res = (res + grid[y][x]) % k;
                    q.push({y,x});
                    grid[y][x] = 0;
                }
            };
            push(y,x);
            while(q.size()) {
                auto [y,x] = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(0 <= ny and ny < n and 0 <= nx and nx < m) push(ny,nx);
                }
            }
            return res == 0;
        };
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(grid[i][j]) res += bfs(i,j);
        return res;
    }
};
