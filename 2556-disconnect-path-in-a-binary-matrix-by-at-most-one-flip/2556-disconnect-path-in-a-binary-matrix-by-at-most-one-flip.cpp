class Solution {
    vector<vector<int>> bfs(vector<vector<int>>& A, int sy, int sx, vector<int> dy, vector<int> dx) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> res(n,vector<int>(m));
        queue<pair<int,int>> q;
        auto push = [&](int y, int x) {
            if(0 <= y and y < n and 0 <= x and x < m and A[y][x] and !res[y][x]) {
                res[y][x] = true;
                q.push({y,x});
            }
        };
        push(sy,sx);
        while(q.size()) {
            auto [y,x] = q.front(); q.pop();
            for(int i = 0; i < 2; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                push(ny,nx);
            }
        }
        return res;
    }
public:
    bool isPossibleToCutPath(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        auto mat1 = bfs(A,n-1,m-1,{-1,0},{0,-1});
        auto mat2 = bfs(A,0,0,{1,0},{0,1});
        vector<int> dp(n*m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int now = mat1[i][j] and mat2[i][j];
                dp[i+j] += now;
            }
        }
        for(int i = 1; i < (n - 1 + m - 1); i++) if(dp[i] <= 1) return true;
        return false;
    }
};