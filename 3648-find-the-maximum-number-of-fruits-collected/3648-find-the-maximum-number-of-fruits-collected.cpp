class Solution {
    int helper(vector<vector<int>>& A, vector<pair<int,int>> D, int y, int x) {
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

        while(q.size()) {
            auto [y,x,cost] = q.front(); q.pop();
            if(vis[y][x][0] != cost) continue;
            for(auto& [dy,dx] : D) {
                int ny = y + dy, nx = x + dx;
                if(0 <= ny and ny < n and 0 <= nx and nx < m) {
                    push(ny,nx,cost + A[ny][nx], y, x);
                }
            }
        }
        return vis[n-1][n-1][0];
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int res = 0, n = fruits.size();
        
        res += helper(fruits, {{1,1}}, 0,0);
        for(int i = 0; i < n; i++) fruits[i][i] = 0;
        res += helper(fruits, {{1,-1},{1,0},{1,1}}, 0, n - 1);
        res += helper(fruits, {{-1,1},{0,1},{1,1}}, n - 1,0);
        
        return res;
    }
};