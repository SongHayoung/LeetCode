long long vis[77][77][77][4];
class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        memset(vis,0x3f3f3f3f3f3f3f3fLL,sizeof(vis));
        priority_queue<array<int,5>,vector<array<int,5>>, greater<>> q;
        auto push = [&](int y, int x, int t, int d, int c) {
            if(t <= k and 0 <= y and y < n and 0 <= x and x < m and vis[y][x][t][d] > c) {
                q.push({c,y,x,t,d});
                vis[y][x][t][d] = c;
            }
        };
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        for(int i = 0; i < 4; i++) push(0,0,0,i,grid[0][0]);
        while(q.size()) {
            auto [c,y,x,t,d] = q.top(); q.pop();
            if(y == n - 1 and x == m - 1) return c;
            if(vis[y][x][t][d] != c) continue;
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m) {
                    push(ny,nx,t + (d != i), i, c + grid[ny][nx]);
                }
            }
        }
        return -1;
    }
};