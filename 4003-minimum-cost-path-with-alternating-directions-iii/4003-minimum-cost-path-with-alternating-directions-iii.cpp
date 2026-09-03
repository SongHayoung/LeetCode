class Solution {
public:
    long long minCost(int n, int m, vector<vector<int>>& penalty) {
        vector<vector<vector<long long>>> cost(n,vector<vector<long long>>(m, vector<long long>(2, LLONG_MAX)));
        priority_queue<array<long long,4>,vector<array<long long,4>>,greater<array<long long,4>>> q;
        auto push = [&](long long c, long long y, long long x, long long fl) {
            if(cost[y][x][fl] > c) {
                cost[y][x][fl] = c;
                q.push({c,y,x,fl});
            }
        };
        push(1,0,0,0);
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        auto bad = [&](int dir, int fl) {
            if(fl == 0) return dir == 0 or dir == 3;
            return dir == 1 or dir == 2;
        };
        while(q.size()) {
            auto [c,y,x,fl] = q.top(); q.pop();
            if(cost[y][x][fl] != c) continue;
            push(c + penalty[y][x], y, x, !fl);
            for(int i = 0; i < 4; i++) {
                long long ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m) {
                    long long nc = c + (ny + 1) * (nx + 1) + (bad(i,fl) ? penalty[y][x] : 0);
                    push(nc,ny,nx,!fl);
                }
            }
        }
        return min(cost[n-1][m-1][0], cost[n-1][m-1][1]);
    }
};