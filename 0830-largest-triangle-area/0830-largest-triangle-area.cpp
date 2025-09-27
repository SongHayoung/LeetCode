
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double res = 0.;
        for(int i = 0; i < points.size(); i++) for(int j = i + 1; j < points.size(); j++) for(int k = j + 1; k < points.size(); k++) {
            long long x1 = points[j][0] - points[i][0];
            long long y1 = points[j][1] - points[i][1];
            long long x2 = points[k][0] - points[i][0];
            long long y2 = points[k][1] - points[i][1];
            res = max(res, abs(x1 * y2 - x2 * y1) * 0.5);
        }
        return res;
    }
};
