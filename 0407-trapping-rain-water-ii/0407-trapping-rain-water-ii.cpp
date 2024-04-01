class Solution {
public:
    int trapRainWater(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<array<long long, 3>>> q;
        vector<vector<int>> vis(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            vis[i][0] = vis[i][m-1] = true;
            q.push({A[i][0],i,0});
            q.push({A[i][m-1],i,m-1});
        }
        for(int j = 1; j < m-1; j++) {
            vis[0][j] = vis[n-1][j] = true;
            q.push({A[0][j], 0, j});
            q.push({A[n-1][j], n-1, j});
        }
        int res = 0;
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        while(q.size()) {
            auto [h,y,x] = q.top(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and !vis[ny][nx]) {
                    vis[ny][nx] = true;
                    res += max(0ll, h - A[ny][nx]);
                    q.push({max(h, 1ll * A[ny][nx]), ny, nx});
                }
            }
        }
        return res;
    }
};