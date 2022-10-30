class Solution {
    int visit[41][41][1601];
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        if(n == 1 and m == 1) return 0;
        int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
        memset(visit, -1, sizeof(visit));
        visit[0][0][k] = 0;
        queue<vector<int>> q;
        q.push({0,0,k});
        while(!q.empty()) {
            auto vec = q.front();
            q.pop();
        
            int cy = vec[0], cx = vec[1], ck = vec[2];
            for(int i = 0; i < 4; i++) {
                int nx = cx + dx[i], ny = cy + dy[i];
                if(0 <= nx and nx < m and 0 <= ny and ny < n) {
                    if(grid[ny][nx] == 0 and visit[ny][nx][ck] == -1) {
                        q.push({ny,nx,ck});
                        visit[ny][nx][ck] = visit[cy][cx][ck] + 1;
                        if(ny == n - 1 and nx == m - 1) return visit[ny][nx][ck];
                    } else if(grid[ny][nx] == 1 and ck and visit[ny][nx][ck-1] == -1) {
                        q.push({ny,nx,ck-1});
                        visit[ny][nx][ck-1] = visit[cy][cx][ck] + 1;
                        if(ny == n - 1 and nx == m - 1) return visit[ny][nx][ck-1];
                    }
                }
            }
        }

        return -1;
    }
};