class Solution {
public:
    bool hasPath(vector<vector<int>>& A, vector<int>& s, vector<int>& d) {
        int n = A.size(), m = A[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>> vis(n,vector<int>(m));
        auto push = [&](int y, int x) {
            if(vis[y][x]) return;
            vis[y][x] = true;
            q.push({y,x});
        };
        push(s[0],s[1]);
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        auto ok = [&](int y, int x) {
            return 0 <= y and y < n and 0 <= x and x < m and A[y][x] == 0;
        };
        while(q.size()) {
            auto [y,x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y, nx = x;
                while(ok(ny + dy[i], nx + dx[i])) ny += dy[i], nx += dx[i];
                push(ny,nx);
            }
        }
        
        return vis[d[0]][d[1]];
    }
};