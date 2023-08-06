class Solution {
    int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
    bool bfs(vector<vector<int>>& A, int k) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        queue<pair<int, int>> q;
        auto push = [&](int y, int x) {
            if(A[y][x] >= k and !vis[y][x]) {
                q.push({y,x});
                vis[y][x] = true;
            }
        };
        push(0,0);
        while(q.size()) {
            auto [y,x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m) {
                    push(ny,nx);
                }
            }
        }
        return vis[n-1][m-1];
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> safe(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        auto push =[&](int y, int x, int c)  {
            if(safe[y][x] == -1) {
                safe[y][x] = c;
                q.push({y,x});
            }
        };
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(A[i][j]) push(i,j,0);
        }
        while(q.size()) {
            auto [y,x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m) {
                    push(ny,nx,safe[y][x] + 1);
                }
            }
        }
        int l = 0, r = n + m, res = l;
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = bfs(safe,m);
            if(ok) {
                res = max(res, m);
                l = m + 1;
            } else r = m - 1;
        }
        return res;
    }
};