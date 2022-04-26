#define topK(a,k) begin(a), begin(a) + k, end(a)
class Solution {
    int manhattanDistance(int x1, int y1, int x2, int y2) {
        return abs(x1-x2) + abs(y1-y2);
    }
public:
    int minDayskVariants(vector<vector<int>>& P, int k) {
        int l = 100, r = 0, t = 0, b = 100;
        for(auto& p : P) {
            l = min(l, p[0]);
            r = max(r, p[0]);
            b = min(b, p[1]);
            t = max(t, p[1]);
        }
        int res = INT_MAX;
        for(int x = l; x <= r; x++) {
            for(int y = b; y <= t; y++) {
                vector<int> d;
                for(auto& p : P) {
                    d.push_back(manhattanDistance(x,y,p[0],p[1]));
                }
                partial_sort(topK(d,k));
                res = min(res, d[k-1]);
            }
        }
        return res;
    }
};