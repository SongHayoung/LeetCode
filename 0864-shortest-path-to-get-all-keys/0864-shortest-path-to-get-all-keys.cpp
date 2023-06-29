class Solution {
    
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].length(), key = 0;
        unordered_map<char, int> keymp;
        queue<array<int,3>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '@') {
                    q.push({i,j,0});
                } else if(islower(grid[i][j])) {
                    keymp[grid[i][j]] = key++;
                }
            }
        }
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(1<<key, false)));
        if(!key) return 0;
        vis[q.front()[0]][q.front()[1]][q.front()[2]] = true;
        int res = 1;
        int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [y, x, mask] = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(0 <= ny and ny < n and 0 <= nx and nx < m and !vis[ny][nx][mask] and grid[ny][nx] != '#') {
                        if(islower(grid[ny][nx])) { //key
                            vis[ny][nx][mask] = true;
                            int nmask = mask | (1<<keymp[grid[ny][nx]]);
                            if(nmask == ((1<<key) - 1)) return res;
                            q.push({ny,nx,nmask});
                        } else if(isupper(grid[ny][nx])) { //lock
                            char low = grid[ny][nx] - 'A' + 'a';
                            if(keymp.count(low) and (1<<keymp[low]) & mask) {
                                vis[ny][nx][mask] = true;
                                q.push({ny,nx,mask});
                            }
                        } else { // dot
                            vis[ny][nx][mask] = true;
                            q.push({ny,nx,mask});
                        }
                        
                    }
                }
            }
            res++;
        }
        return -1;
    }
};