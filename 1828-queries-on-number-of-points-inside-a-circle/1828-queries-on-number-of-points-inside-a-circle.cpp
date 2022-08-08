class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto& q : queries) {
            int cx = q[0], cy = q[1], cr = q[2];
            int now = 0;
            for(auto& p : points) {
                int x = p[0], y = p[1];
                int distance = (cx - x) * (cx - x) + (cy - y) * (cy - y);
                if(distance <= cr * cr) now++;
            }
            res.push_back(now);
        }
        return res;
    }
};