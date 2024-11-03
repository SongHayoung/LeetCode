
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dp(n, vector<int>(m,INT_MAX));
        map<int,queue<array<int,3>>> mq;
        auto push = [&](int y, int x, int c) {
            if(dp[y][x] > c) {
                dp[y][x] = c;
                mq[c].push({c,y,x});
            }
        };
        push(0,0,0);
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        while(mq.size()) {
            auto& q = begin(mq)->second;
            while(q.size()) {
                auto [c,y,x] = q.front(); q.pop();
                if(dp[y][x] != c) continue;
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(0 <= ny and ny < n and 0 <= nx and nx < m) {
                        int cost = max(c, moveTime[ny][nx]) + ((ny + nx) % 2 ? 1 : 2);
                        push(ny,nx,cost);
                    }
                }
            }
            mq.erase(begin(mq));
        }

        return dp[n-1][m-1];
    }
};