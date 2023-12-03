class Solution {
    int helper(vector<int>& p1, vector<int>& p2) {
        return max(abs(p1[0] - p2[0]), abs(p1[1] - p2[1]));
    }
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 1; i < points.size(); i++) {
            res += helper(points[i-1], points[i]);
        }
        return res;
    }
};