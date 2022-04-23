class Solution {
    bool bfs(vector<vector<int>>& h, int limit) {
        int n = h.size(), m = h[0].size();
        int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int,int>> q;
        vis[0][0] = true;
        q.push({0,0});
        
        while(!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and !vis[ny][nx] and abs(h[ny][nx] - h[y][x]) <= limit) {
                    q.push({ny,nx});
                    vis[ny][nx] = true;
                }
            }
        }
        
        return vis[n-1][m-1];
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l = 0, r = INT_MAX, res = INT_MAX;
        while(l <= r) {
            int m = l + (r-l)/2;
            bool reached = bfs(heights, m);
            
            if(reached) {
                res = min(res, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res;
    }
};