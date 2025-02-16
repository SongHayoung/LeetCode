class Solution {
    const long double EPS = 1e-9;
    long long helper(vector<vector<int>>& A, long double bar, long double area) {
        for(auto& a : A) {
            long double y = a[1], yy = a[1] + a[2];
            if(y >= bar) continue;
            area -= (min(yy,bar) - y) * a[2];
        }
        return area <= 0;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        long double area = 0, l = 0, r = 2e9;
        for(auto& s : squares) area += 1ll * s[2] * s[2] / 2.;
        while(r - l > EPS) {
            long double m = l + (r - l) / 2;
            long long ok = helper(squares, m, area);
            if(ok) {
                r = m;
            } else l = m;
        }
        return l;
    }
};
