class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = rooms.size(), m = rooms[0].size(), INF = 2147483647;
        int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!rooms[i][j])
                    q.push({i,j});
            }
        }
        while(!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= nx and nx < m and 0 <= ny and ny < n and rooms[ny][nx] == INF) {
                    rooms[ny][nx] = rooms[y][x] + 1;
                    q.push({ny,nx});
                }
            }
        }
    }
};