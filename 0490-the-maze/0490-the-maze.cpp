class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        queue<pair<int, int>> q;
        int n = maze.size(), m = maze[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m));
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        auto push = [&](int y, int x) {
            if(!vis[y][x]) {
                q.push({y,x});
                vis[y][x] = true;
            }
        };
        push(start[0], start[1]);
        while(q.size()) {
            auto [y,x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y, nx = x;
                while(0 <= ny + dy[i] and ny + dy[i] < n and 0 <= nx + dx[i] and nx + dx[i] < m and maze[ny+dy[i]][nx+dx[i]] == 0) {
                    ny = ny + dy[i];
                    nx = nx + dx[i];
                }
                push(ny,nx);
            }
        }
        return vis[destination[0]][destination[1]];
    }
};