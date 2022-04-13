class Solution {
    unordered_map<long, vector<pair<vector<int>, vector<int>>>> mp;
    long middle(vector<int>& p1, vector<int>& p2) {
        long y = (p1[0] + p2[0]);
        long x = (p1[1] + p2[1]);
        return y * 1e5 + x;
    }
    double distance(vector<int>& p1, vector<int>& p2) {
        int y = p1[0] - p2[0];
        int x = p1[1] - p2[1];
        return y * y + x * x;
    }
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
                long m = middle(points[i], points[j]);
                mp[m].push_back({points[i], points[j]});
            }
        }
        double res = DBL_MAX;
        for(auto [m, vec] : mp) {
            for(int i = 0; i < vec.size(); i++) {
                for(int j = i + 1; j < vec.size(); j++) {
                    if(
                        (vec[i].first[0] - vec[j].first[0]) * (vec[i].first[0] - vec[j].second[0]) +
                        (vec[i].first[1] - vec[j].first[1]) * (vec[i].first[1] - vec[j].second[1]) == 0) {
                        res = min(res, distance(vec[i].first, vec[j].first)*distance(vec[i].first, vec[j].second));
                    }
                }
            }
        }
        return res == DBL_MAX ? 0 : sqrt(res);
    }
};