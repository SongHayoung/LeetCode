class Solution {
public:
    bool isReflected(vector<vector<int>>& points) {
        if(points.size()<=1)
        {
            return true;
        }
        set<pair<int,int>>pts;
        int maxi{INT_MIN},mini{INT_MAX};
        for(auto&point:points)
        {
            pts.insert(make_pair(point[0],point[1]));
            maxi = max(maxi, point[0]);
            mini = min(mini, point[0]);
        }
        double y{0};
        y=double(maxi-mini)/2+mini;
        for(auto&a:pts)
        {
            if(!pts.count({y*2 - a.first , a.second }))
            {
                return false;
            }
        }
        return true;
    }
};