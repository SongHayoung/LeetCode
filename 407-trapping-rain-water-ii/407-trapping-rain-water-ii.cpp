class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int n = h.size(), m = h[0].size(), res = 0;
        int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> pq;
        for(int i = 0; i < n; i++) {
            visit[i][0] = visit[i][m-1] = true;
            pq.push({h[i][0], i, 0});
            pq.push({h[i][m-1], i, m - 1});
        }
        for(int i = 0; i < m; i++) {
            visit[0][i] = visit[n-1][i] = true;
            pq.push({h[0][i], 0, i});
            pq.push({h[n-1][i], n-1, i});
        }
        while(!pq.empty()) {
            auto [hi, y, x] = pq.top(); pq.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and !visit[ny][nx]) {
                    visit[ny][nx] = true;
                    res += max(0, hi - h[ny][nx]);
                    pq.push({max(hi,h[ny][nx]), ny, nx});
                }
            }
        }
        return res;
    }
};