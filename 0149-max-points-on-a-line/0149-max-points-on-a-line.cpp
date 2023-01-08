class Solution {
    int gcd(int p, int q) {
        return !q ? p : gcd(q, p % q);
    }
    string getInclinations(vector<int>& a, vector<int>& b) {
        int dx = a[1] - b[1];
        int dy = a[0] - b[0];
        if(!dx) return "1|0";
        if(!dy) return "0|1";
        int sign = dx * dy < 0 ? -1 : 1;
        dx = abs(dx), dy = abs(dy);
        int GCD = gcd(dx, dy);
        return to_string(sign * dy / GCD) + "|" + to_string(dx / GCD);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 1;
        for(int i = 0; i < n; i++) {
            unordered_map<string, int> table;
            for(int j = i + 1; j < n; j++) {
                auto inc = getInclinations(points[i], points[j]);
                res = max(res, ++table[inc] + 1);
            }
        }

        return res;
    }
};