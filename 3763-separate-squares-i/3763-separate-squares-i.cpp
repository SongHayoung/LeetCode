class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        auto getAreaBelow = [&](double y) {
            double area = 0;
            for (auto& square : squares) {
                double xi = square[0], yi = square[1], l = square[2];
                if (y > yi) {
                    double overlapHeight = min(y - yi, l);
                    area += overlapHeight * l;
                }
            }
            return area;
        };

        double totalArea = 0;
        for (auto& square : squares) {
            double l = square[2];
            totalArea += l * l; // Use double for all area calculations
        }
        double targetArea = totalArea / 2.0;

        double left = 0, right = 2e9; // Adjusted upper bound to 2e9
        while (right - left > 1e-5) { // Adjusted precision to 1e-5
            double mid = (left + right) / 2;
            if (getAreaBelow(mid) < targetArea) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};