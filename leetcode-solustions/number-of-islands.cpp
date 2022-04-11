class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0, dx[4]{0,1,0,-1}, dy[4]{-1,0,1,0}, n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] & 0b1111) {
                    res++;
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    grid[i][j] = 48;
                    while(!q.empty()) {
                        auto p = q.front();
                        q.pop();
                        for(int k = 0; k < 4; k++) {
                            int nx = p.second + dx[k], ny = p.first + dy[k];
                            if(0 <= nx && nx < m && 0 <= ny && ny < n && grid[ny][nx] & 0b1111) {
                                q.push({ny,nx});
                                grid[ny][nx] = 48;
                            }
                        }
                    }
                }
            }
        }

        return res;
    }
};
