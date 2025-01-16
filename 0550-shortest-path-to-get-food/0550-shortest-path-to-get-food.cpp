class Solution {
public:
    int getFood(vector<vector<char>>& A) {
        int n = A.size(), m = A[0].size();
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        queue<pair<int,int>> q;
        auto push = [&](int y, int x) {
            A[y][x] = 'X';
            q.push({y,x});
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == '*') push(i,j);
            }
        }
        int res = 1;
        while(q.size()) {
            int qsz = q.size();
            while(qsz--) {
                auto [y,x] = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(0 <= ny and ny < n and 0 <= nx and nx < m and A[ny][nx] != 'X') {
                        if(A[ny][nx] == '#') return res;
                        push(ny,nx);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};