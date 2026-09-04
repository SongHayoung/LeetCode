class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());
        double a = sides[0], b = sides[1], c = sides[2];
        if (a + b <= c) return {};
        
        const double PI = acos(-1.0);
        auto getAngle = [&](double x, double y, double z) {
            double v = (y * y + z * z - x * x) / (2.0 * y * z);
            v = max(-1.0, min(1.0, v));
            return acos(v) * 180.0 / PI;
        };
        
        vector<double> res = {
            getAngle(a, b, c),
            getAngle(b, a, c),
            getAngle(c, a, b)
        };
        sort(res.begin(), res.end());
        return res;
    }
};