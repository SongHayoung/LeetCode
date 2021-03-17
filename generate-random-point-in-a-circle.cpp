class Solution {
private:
    double r;
    double x;
    double y;
public:
    Solution(double radius, double x_center, double y_center) : r(radius), x(x_center), y(y_center) {}

    vector<double> randPoint() {
        double theta = rand() * 1.0 / RAND_MAX * 2 * M_PI;
        double hypotenuse = sqrt(rand() * 1.0 / RAND_MAX) * r;
        return vector<double> {cos(theta) * hypotenuse + x, sin(theta) * hypotenuse + y};
    }
};
