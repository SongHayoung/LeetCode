

class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        pair<long long, long long> x{INT_MAX, INT_MIN}, y{INT_MAX, INT_MIN};
        unordered_map<long long, pair<long long, long long>> xmp, ymp;
        auto udt = [&](pair<long long, long long>& p, long long pos) {
            p.first = min(p.first, pos);
            p.second = max(p.second, pos);
        };
        for(auto& c : coords) {
            long long yp = c[0], xp = c[1];
            udt(x,xp);
            udt(y,yp);
            if(!xmp.count(xp)) xmp[xp] = {INT_MAX, INT_MIN};
            if(!ymp.count(yp)) ymp[yp] = {INT_MAX, INT_MIN};
            udt(xmp[xp], yp);
            udt(ymp[yp], xp);
        }
        long long res = 0;
        for(auto& [dep, pr] : xmp) {
            long long len = pr.second - pr.first;
            long long dif = max(abs(dep - x.first), abs(dep - x.second));
            res = max(res, len * dif);
        }
        for(auto& [dep, pr] : ymp) {
            long long len = pr.second - pr.first;
            long long dif = max(abs(dep - y.first), abs(dep - y.second));
            res = max(res, len * dif);
        }
        return res ? res : -1;
    }
};