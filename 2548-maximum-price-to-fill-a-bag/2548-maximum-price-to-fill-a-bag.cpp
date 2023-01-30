class Solution {
public:
    double maxPrice(vector<vector<int>>& items, int capacity) {
        vector<array<double,3>> S;
        for(auto item : items) {
            int p = item[0], w = item[1];
            double r = 1. * p / w;
            S.push_back({r,1. * p,1. * w});
        }
        sort(begin(S), end(S));
        double res = 0;
        while(capacity and S.size()) {
            auto [r,p,w] = S.back(); S.pop_back();
            double ma = min(1. * capacity, w);
            capacity -= ma;
            res += r * ma;
        }
        return capacity ? -1 : res;
    }
};
