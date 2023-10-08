class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(start == destination) return 0;
        int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1}, n = maze.size(), m = maze[0].size();
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;
        pq.push({0,start[0],start[1]});
        int v[n][m];
        memset(v,-1,sizeof(v));
        while(!pq.empty()) {
            auto [mv, y, x] = pq.top(); pq.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y, nx = x, move = 0;
                while(0 <= ny + dy[i] and ny + dy[i] < n and 0 <= nx + dx[i] and nx + dx[i] < m and maze[ny + dy[i]][nx + dx[i]] == 0) {
                    move++;
                    ny += dy[i], nx += dx[i];
                }
                if(v[ny][nx] == -1 or v[ny][nx] > move + mv) {
                    v[ny][nx] = move + mv;
                    pq.push({move + mv, ny, nx});
                    if(ny == destination[0] and nx == destination[1]) return move + mv;
                }
            }
        }
        return -1;
    }
};