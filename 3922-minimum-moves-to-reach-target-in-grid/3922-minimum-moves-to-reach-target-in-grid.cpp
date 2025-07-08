class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        if(sx == tx and sy == ty) return 0;
        queue<pair<int,int>> q;
        set<pair<int,int>> vis;
        auto push = [&](int x, int y) {
            if(!vis.count({x,y}) and x >= sx and y >= sy) {
                vis.insert({x,y});
                q.push({x,y});
            }
        };
        int res = 0;
        push(tx,ty);
        while(q.size()) {
            int qsz = q.size();
            while(qsz--) {
                auto [x,y] = q.front(); q.pop();
                if(x >= y) {
                    if(x % 2 == 0) {
                        int X = x / 2;
                        if(X >= y) {
                            if(X == sx and y == sy) return res + 1;
                            push(X,y);
                        }
                    }
                    if(x - y <= y) {
                        if(x - y == sx and y == sy) return res + 1;
                        push(x - y, y);
                    }
                }
                if(x <= y) {
                    if(y % 2 == 0) {
                        int Y = y / 2;
                        if(Y >= x) {
                            if(x == sx and Y == sy) return res + 1;
                            push(x, Y);
                        }
                    }
                    if(y - x <= x) {
                        if(x == sx and y - x == sy) return res + 1;
                        push(x, y - x);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};