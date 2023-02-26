class Solution {
public:
    int minimumTime(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        priority_queue<array<int,4>, vector<array<int,4>>, greater<array<int,4>>> q;
        q.push({0,0,0,0});
        vector<vector<vector<int>>> vis(n,vector<vector<int>>(m, vector<int>(2,INT_MAX)));
        vis[0][0][0] = 0;
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        while(q.size()) {
            auto[v, fl, y, x] = q.top();
            q.pop();
            if (vis[y][x][fl] != v) continue;
            bool less = false;
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if (0 <= ny and ny < n and 0 <= nx and nx < m) {
                    if (A[ny][nx] <= v + 1) less = true;
                }
            }
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if (0 <= ny and ny < n and 0 <= nx and nx < m) {
                    if (A[ny][nx] <= v + 1) {
                        if (vis[ny][nx][!fl] > v + 1) {
                            vis[ny][nx][!fl] = v + 1;
                            q.push({vis[ny][nx][!fl], !fl, ny, nx});
                        }
                    } else if (less) {
                        int req = A[ny][nx] - (v + 1);
                        if (req & 1) req += 1;
                        req += 1;
                        if (vis[ny][nx][fl] > v + req) {
                            vis[ny][nx][fl] = v + req;
                            q.push({vis[ny][nx][fl], fl, ny, nx});
                        }
                    }
                }
            }
        }

        int res = min(vis[n-1][m-1][0], vis[n-1][m-1][1]);
        return res == INT_MAX ? -1 : res;
    }
};

