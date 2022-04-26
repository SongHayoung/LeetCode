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
        db res = DBL_MAX, X = 0, Y = 0;
        for(db alpha = 10; alpha >= 1e-5; alpha /= 10) {
            for(db x = l; x <= r; x += alpha) {
                for(db y = b; y <= t; y += alpha) {
                    auto ed = [&](db sum, vector<int>& p) {
                        return sum + sqrt((x-p[0])*(x-p[0]) + (y-p[1])*(y-p[1]));
                    };
                    
                    db d = accumulate(all(P), 0.0, ed);
                    if(res > d) {
                        res = d;
                        X = x;
                        Y = y;
                    }
                }
            }
            l = X - alpha;
            r = X + 2*alpha;
            b = Y - alpha;
            t = Y + 2*alpha;
        }
        return res;
    }
};