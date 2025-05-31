class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> vis(n,vector<int>(m,INT_MAX));
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> q;
        auto push = [&](int cost, int y, int x) {
            if(vis[y][x] > cost) {
                vis[y][x] = cost;
                q.push({cost, y, x});
            }
        };
        push(0,n-1,0);
        auto nextPos = [&](int y, int x) {
            int h = n - y;
            int go = h & 1 ? +1 : -1;
            if(0 <= x + go and x + go < m) return pair<int,int>{y,x + go};
            if(y == 0) return pair<int,int>{-1,-1};
            return pair<int,int>{y-1, x};
        };
        auto where = [&](int pos) {
            pos -= 1;
            int y = n - pos / m - 1;
            int h = n - y;
            int go = h & 1 ? +1 : -1;
            int front = h & 1 ? 0 : m - 1;
            return pair<int, int>{y, front + go * (pos % m)};
        };
        while(q.size()) {
            auto [c,y,x] = q.top(); q.pop();
            if(vis[y][x] != c) continue;
            for(int i = 0; i < 6; i++) {
                auto [ny, nx] = nextPos(y,x);
                if(ny == -1) break;
                if(A[ny][nx] == -1) {
                  push(c + 1, ny, nx);
                } else {
                    auto [yy, xx] = where(A[ny][nx]);
                    push(c + 1, yy, xx);
                }
                y = ny, x = nx;
                
            }
        }
        int& res = vis[0][n & 1 ? m - 1 : 0];
        return res == INT_MAX ? -1 : res;
    }
};