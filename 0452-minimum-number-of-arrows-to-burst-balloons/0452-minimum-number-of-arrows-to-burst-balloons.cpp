class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        long arrow = 0, ma = INT_MIN; ma--;
        sort(points.begin(), points.end());
        for(auto p : points) {
            if(p[0] > ma) {
                arrow++;
                ma = p[1];
            } else {
                ma = min(ma, (long)p[1]);
            }
        }
        return arrow;
    }
};