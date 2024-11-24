class Solution {
    void helper(vector<vector<int>>& A, vector<pair<int,int>> D, int y, int x) {
        int n = A.size(), m = A[0].size();
        vector<vector<array<int,3>>> vis(n, vector<array<int,3>>(m, {-1,-1,-1}));
        queue<array<int,3>> q;
        auto push = [&](int cy, int cx, int cc, int y, int x) {
          if(vis[cy][cx][0] < cc) {
              vis[cy][cx] = {cc,y,x};
              q.push({cy,cx,cc});
          } 
        };
        q.push({y,x,0}); vis[y][x][0] = 0;
        auto reachAble = [&](int cy, int cx) {
            if(y == 0 and x == 0) return true;
            if(x == n - 1) {
                int dis = n - 1 - cy;
                int dix = m - 1 - cx;
                return dix <= dis;
            }
            if(y == m - 1) {
                int dis = n - 1 - cy;
                int dix = m - 1 - cx;
                return dis <= dix;
            }
            return false;
        };
        while(q.size()) {
            auto [y,x,cost] = q.front(); q.pop();
            if(vis[y][x][0] != cost) continue;
            for(auto& [dy,dx] : D) {
                int ny = y + dy, nx = x + dx;
                if(0 <= ny and ny < n and 0 <= nx and nx < m and reachAble(ny,nx)) {
                    push(ny,nx,cost + A[ny][nx], y, x);
                }
            }
        }
        
        y = x = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[y][x][0] < vis[i][j][0]) y = i, x = j;
            }
        }
        while(y >= 0 and x >= 0) {
            A[y][x] = 0;
            int ny = vis[y][x][1], nx = vis[y][x][2];
            y = ny, x = nx;
        }
        
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int res = 0, n = fruits.size();
        for(auto& vec : fruits) for(auto& x : vec) res += x;
        
        helper(fruits, {{1,1}}, 0,0);
        
        helper(fruits, {{1,-1},{1,0},{1,1}}, 0, n - 1);
        helper(fruits, {{-1,1},{0,1},{1,1}}, n - 1,0);
        
        
        for(auto& vec : fruits) for(auto& x : vec) res -= x;
        return res;
    }
};