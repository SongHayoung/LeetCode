class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> cost(n, vector<int>(m,INT_MAX));
        cost[0][0] = 0;
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        queue<pair<int,int>> q; q.push({0,0});
        while(q.size()) {
            auto [y,x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m) {
                    int nc = max(cost[y][x] + 1,moveTime[ny][nx] + 1);
                    if(cost[ny][nx] > nc) {
                        cost[ny][nx] = nc;
                        q.push({ny,nx});
                    }
                }
            }
        }
        return cost[n-1][m-1];
    }
};