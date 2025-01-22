class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& A) {
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        int n = A.size(), m = A[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 0) A[i][j] = -1;
                else if(A[i][j] == 1) A[i][j] = 0;
            }
        }

        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == -1) continue;
                for(int k = 0; k < 4; k++) {
                    int ny = i + dy[k], nx = j + dx[k];
                    if(0 <= ny and ny < n and 0 <= nx and nx < m and A[ny][nx] == -1)
                        q.push({ny,nx});
                }
            }
        }
        while(!q.empty()) {
            queue<pair<int, int>> qq;
            while(!q.empty()) {
                auto [y, x] = q.front(); q.pop();
                int mi = INT_MAX;
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(0 <= ny and ny < n and 0 <= nx and nx < m and A[ny][nx] >= 0) {
                        mi = min(mi, A[ny][nx]);
                    }
                }
                A[y][x] = mi + 1;
                qq.push({y, x});
            }
            while(!qq.empty()) {
                auto [y, x] = qq.front(); qq.pop();
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(0 <= ny and ny < n and 0 <= nx and nx < m and A[ny][nx] == -1) {
                        q.push({ny, nx});
                        A[ny][nx] = -2;
                    }
                }
            }
        }
        
        return A;
    }
};