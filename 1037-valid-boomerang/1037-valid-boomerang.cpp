class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        sort(begin(points), end(points));
        if(points[0][0] == points[1][0] and points[1][0] == points[2][0]) return false;
        if(points[0][1] == points[1][1] and points[1][1] == points[2][1]) return false;
        int da = points[1][0] - points[0][0], db = points[1][1] - points[0][1];
        int dc = points[2][0] - points[1][0], dd = points[2][1] - points[1][1];
        if(!da and !db) return false;
        if(!dc and !dd) return false;
        if(!da or !db or !dc or !dd) return true;
        {
            int g = __gcd(da,db);
            da /= g, db /= g;
        }
        {
            int g= __gcd(dc,dd);
            dc /= g, dd /= g;
        }
        return da * dd != dc * db;
    }
};