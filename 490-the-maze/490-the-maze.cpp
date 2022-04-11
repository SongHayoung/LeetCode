class Solution {

public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(start == destination) return true;

        int n = maze.size(), m = maze[0].size();
        int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
        maze[start[0]][start[1]] = -1;
        queue<vector<int>> q;
        q.push(start);
        while(!q.empty()) {
            auto pos = q.front(); q.pop();
            int y = pos[0], x = pos[1];
            for(int i = 0; i < 4; i++) {
                int ny = y, nx = x;

                while(0 <= ny + dy[i] and ny + dy[i] < n and 0 <= nx + dx[i] and nx + dx[i] < m and maze[ny + dy[i]][nx + dx[i]] <= 0) { //move straight
                    ny += dy[i];
                    nx += dx[i];
                }
                if(!maze[ny][nx]) {
                    maze[ny][nx] = -1;
                    q.push({ny,nx});
                    if(destination[0] == ny and destination[1] == nx) return true;
                }
            }
        }
        return false;
    }
};