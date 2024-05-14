class Solution {
    bool merge(int p, int s, pair<int, int> car, int t) {
        if(s >= car.second) return false;
        int d1 = t - p, d2 = t - car.first;
        return 1ll * d1 * car.second >= 1ll * d2 * s;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> A;
        for(int i = 0; i < speed.size(); i++) A.push_back({position[i], speed[i]});
        sort(begin(A), end(A));
        int res = 0;
        while(A.size()) {
            auto [p,s] = A.back(); A.pop_back();
            while(A.size() and merge(p,s,A.back(),target)) A.pop_back();
            res++;
        }
        return res;
    }
};