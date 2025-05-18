class Solution {
public:
    int minMoves(vector<string>& A) {
        int n = A.size(), m = A[0].size();
        if(A[0][0] == '#' or A[n-1][m-1] == '#') return -1;
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
        unordered_map<char,vector<pair<int,int>>> tel;
        queue<pair<int,int>> q;
        auto push = [&](int y, int x, int c) {
            if(cost[y][x] == INT_MAX) {
                cost[y][x] = c;
                q.push({y,x});
            }
        };
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(isalpha(A[i][j])) tel[A[i][j]].push_back({i,j});
        }
        push(0,0,0);
        if(tel.count(A[0][0])) {
            for(auto& [y,x] : tel[A[0][0]]) push(y,x,0);
            tel.erase(A[0][0]);
        }
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        while(q.size()) {
            auto [y,x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and A[ny][nx] != '#') {
                    push(ny,nx,cost[y][x] + 1);
                    if(tel.count(A[ny][nx])) {
                        for(auto& [nny,nnx] : tel[A[ny][nx]]) push(nny,nnx,cost[y][x] + 1);
                        tel.erase(A[ny][nx]);
                    }
                }
            }
        }
        return cost[n-1][m-1] == INT_MAX ? -1 : cost[n-1][m-1];
    }
};