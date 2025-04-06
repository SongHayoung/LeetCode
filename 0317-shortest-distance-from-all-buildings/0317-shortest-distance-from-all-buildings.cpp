class Solution {
    int cnt[55][55], d[55][55], t;
    int n,m;
    int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
    void bfs(vector<vector<int>>& A, int y, int x) {
        vector<vector<bool>> vis(n,vector<bool>(m));
        queue<pair<int,int>> q;
        auto push = [&](int y, int x) {
            if(!vis[y][x]) {
                vis[y][x] = true;
                q.push({y,x});
            }
        };
        push(y,x);
        int dis = 1;
        while(q.size()) {
            int qsz = q.size();
            while(qsz--) {
                auto [y,x] = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(0 <= ny and ny < n and 0 <= nx and nx < m and !A[ny][nx] and !vis[ny][nx]) {
                        push(ny,nx);
                        cnt[ny][nx]++;
                        d[ny][nx] += dis;
                    }
                }
            }
            dis++;
        }
    }
public:
    int shortestDistance(vector<vector<int>>& A) {
        memset(cnt,0,sizeof cnt);
        memset(d,0,sizeof d);
        t = 0;
        n = A.size(), m = A[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 1) {
                    t++;
                    bfs(A,i,j);
                }
            }
        }
        int res = INT_MAX;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 0 and cnt[i][j] == t) res = min(res, d[i][j]);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};