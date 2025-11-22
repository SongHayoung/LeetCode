
map<array<int,3>,pair<int,int>> dp;
class Solution {
    int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
    int masking(int y, int x, int m) {
        return 1<<(y * m + x);
    }
public:
    vector<vector<int>> findPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<int> must(k + 2);
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(grid[i][j]) must[grid[i][j] + 1] |= masking(i,j,m);
        }
        for(int i = 1; i <= k; i++) must[i] |= must[i-1];
        queue<array<int,3>> q;
        auto push = [&](int y, int x, int mask, int py, int px) {
            mask |= masking(y,x,m);
            if(dp.count({y,x,mask})) return;
            
            q.push({y,x,mask});
            dp[{y,x,mask}] = {py,px};
        };
        dp.clear();
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) if(grid[i][j] <= 1) push(i,j,0,-1,-1);
        int full = (1<<(n * m)) - 1, y = -1, x = -1;
        while(q.size()) {
            auto [cy,cx,mask] = q.front(); q.pop();
            if(mask == full) {
                y = cy, x = cx;
                break;
            }
            for(int i = 0; i < 4; i++) {
                int ny = cy + dy[i], nx = cx + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and (mask & masking(ny,nx,m)) == 0) {
                    if(grid[ny][nx] == 0) push(ny,nx,mask,cy,cx);
                    else {
                        if((must[grid[ny][nx]] & mask) == must[grid[ny][nx]]) push(ny,nx,mask,cy,cx);
                    }
                }
            }
        }
        if(y == -1) return {};
        vector<vector<int>> res;
        while(y != -1) {
            res.push_back({y,x});
            auto [ny,nx] = dp[{y,x,full}];
            full ^= masking(y,x,m);
            y = ny, x = nx;
        }
        reverse(begin(res), end(res));
        return res;
    }
};