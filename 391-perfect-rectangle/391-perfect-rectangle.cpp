class Solution {
    string makeKey(int a, int b) {
        return to_string(a) + '#' + to_string(b);
    }
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        if(rectangles.size() == 1) return true;
        int area = 0, minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
        unordered_set<string> points;
        for(auto& rec : rectangles) {
            minx = min(minx, rec[0]);
            miny = min(miny, rec[1]);
            maxx = max(maxx, rec[2]);
            maxy = max(maxy, rec[3]);

            string k1 = makeKey(rec[0],rec[1]);
            string k2 = makeKey(rec[0],rec[3]);
            string k3 = makeKey(rec[2],rec[1]);
            string k4 = makeKey(rec[2],rec[3]);

            if(!points.insert(k1).second) points.erase(k1);
            if(!points.insert(k2).second) points.erase(k2);
            if(!points.insert(k3).second) points.erase(k3);
            if(!points.insert(k4).second) points.erase(k4);
            

            area += abs(rec[2] - rec[0]) * abs(rec[3] - rec[1]);
        }
        if(!points.count(makeKey(minx,miny)) ||!points.count(makeKey(minx,maxy)) ||!points.count(makeKey(maxx,miny)) ||!points.count(makeKey(maxx,maxy)) || points.size() != 4)
            return false;

        return area == abs(maxx - minx)*abs(maxy - miny);
    }
};