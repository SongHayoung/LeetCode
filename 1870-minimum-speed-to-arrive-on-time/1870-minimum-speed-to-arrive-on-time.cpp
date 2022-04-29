class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if((dist.size() - 1) * 1.0 > hour) return -1;
        long l = 0, r = INT_MAX, m;
        int res = INT_MAX;
        while(l <= r) {
            m = (l + r) / 2;
            double sum = 0;
            for(auto d : dist) {
                sum = ceil(sum);
                sum += d * 1.0 / m;
            }
            if(sum <= hour) {
                r = m - 1;
                res = min(res, (int)m);
            } else {
                l = m + 1;
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};