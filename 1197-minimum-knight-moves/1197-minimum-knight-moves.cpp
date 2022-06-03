class Solution {
public:
    int minKnightMoves(int x, int y) {
        if(!x && !y) return 0;
        int dx[8]{1, 2, 2, 1, -1, -2, -2, -1}, dy[8]{-2, -1, 1, 2, 2, 1, -1, -2}, res = 0;
        x = abs(x), y = abs(y);
        set<pair<int, int>> s;
        queue<pair<int, int>> q;
        s.insert({0, 0});
        q.push({0, 0});
        while(!q.empty()) {
            res++;
            int sz = q.size();
            while(sz--) {
                auto p = q.front();
                q.pop();
                for(int i = 0; i < 8; i++) {
                    int nx = p.second + dx[i], ny = p.first + dy[i];
                    if(nx == x && ny == y) return res;
                    if(ny < -10 || nx < -10 || s.count({ny, nx})) continue;
                    s.insert({ny, nx});
                    q.push({ny, nx});
                }
            }
        }

        return -1;
    }
};