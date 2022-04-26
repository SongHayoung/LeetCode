#define db double
#define all(a) begin(a), end(a)
class Solution {
public:
    double getMinDistSum(vector<vector<int>>& P) {
        db t = 0, b = 100, l = 100, r = 0;
        for(auto& p : P) {
            t = max(t, (db) p[1]);
            b = min(b, (db) p[1]);
            l = min(l, (db) p[0]);
            r = max(r, (db) p[0]);
        }
        db res = DBL_MAX, X = 0, Y = 0, gab = 10;
        while(gab >= 1e-5) {
            for(db x = l; x <= r; x += gab) {
                for(db y = b; y <= t; y += gab) {
                    db distance = accumulate(all(P), 0.0, [&](db sum, vector<int>& p) {
                        return sum + sqrt((x-p[0])*(x-p[0]) + (y-p[1])*(y-p[1]));
                    });
                    if(res > distance) {
                        res = distance;
                        X = x;
                        Y = y;
                    }
                }
            }
            l = X - gab;
            r = X + 2*gab;
            b = Y - gab;
            t = Y + 2*gab;
            gab /= 10;
        }
        return res;
    }
};