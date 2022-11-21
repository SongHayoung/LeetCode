class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int dx[4]{0, 1, 0, -1}, dy[4]{-1,0,1,0}, n(maze.size()), m(maze[0].size()), res(0);
        queue<pair<int, int>> q;
        maze[e[0]][e[1]] = '+';
        q.push({e[0], e[1]});
        while(!q.empty()) {
            ++res;
            int sz = q.size();
            while(sz--) {
                auto pos = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int ny(pos.first + dy[i]), nx(pos.second + dx[i]);
                    if(0 <= nx && nx < m && 0 <= ny && ny < n && maze[ny][nx] == '.') {
                        if(nx == 0 || ny == 0 || nx == m-1 || ny == n-1) return res;
                        q.push({ny, nx});
                        maze[ny][nx] = '+';
                    }
                }
            }
        }
        return -1;
    }
};