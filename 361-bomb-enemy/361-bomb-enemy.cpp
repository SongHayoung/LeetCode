class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), r = 0, res = 0;
        vector<int> c(m,0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'W') continue;
                if(j == 0 || grid[i][j-1] == 'W') {
                    r = 0;
                    int x = j;
                    while(x < m and grid[i][x] != 'W') {
                        if(grid[i][x] == 'E') r++;
                        x++;
                    }
                }
                if(i == 0 || grid[i-1][j] == 'W') {
                    c[j] = 0;
                    int y = i;
                    while(y < n and grid[y][j] != 'W') {
                        if(grid[y][j] == 'E') c[j]++;
                        y++;
                    }
                }
                if(grid[i][j] == '0') {
                    res = max(res, r + c[j]);
                }
            }
        }
        return res;
    }
};