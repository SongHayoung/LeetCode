class Solution {
    int n,m;
    vector<int> bfs(vector<vector<int>>& A, int sy, int sx) {
        int ty = sy, tx = sx, by = sy, bx = sx;
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        queue<pair<int, int>> q;
        q.push({sy,sx});
        A[sy][sx] = 0;
        while(!q.empty()) {
            auto [y,x] = q.front(); q.pop();
            ty = min(y,ty);
            tx = min(x,tx);
            by = max(y,by);
            bx = max(x,bx);
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and A[ny][nx] == 1) {
                    A[ny][nx] = 0;
                    q.push({ny,nx});
                }
            }
        }
        
        return {ty,tx,by,bx};
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size(), m = land[0].size();
        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(land[i][j] == 0) continue;
                res.push_back(bfs(land, i,j));
            }
        }
        return res;
    }
};