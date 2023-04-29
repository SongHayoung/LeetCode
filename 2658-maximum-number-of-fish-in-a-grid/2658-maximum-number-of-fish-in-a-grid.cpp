class Solution {
    int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
  
public:
    int findMaxFish(vector<vector<int>>& A) {
        int res = 0, n = A.size(), m = A[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j] == 0) continue;
                int now = 0;
                queue<pair<int, int>> q;
                auto push = [&](int y, int x) {
                    if(0 <= y and y < n and 0 <= x and x < m and A[y][x]) {
                        now += A[y][x];
                        A[y][x] = 0;
                        q.push({y,x});
                    }
                };
                push(i,j);
                while(q.size()) {
                    auto [y,x] = q.front(); q.pop();
                    for(int i = 0; i < 4; i++) {
                        push(y + dy[i], x + dx[i]);
                    }
                }
                res = max(res, now);
            }
        }
        return res;
    }
};