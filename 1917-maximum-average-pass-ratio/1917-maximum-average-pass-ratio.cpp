class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto Compare = [](pair<long long, long long> &a, pair<long long, long long> &b) {
            auto [at, ap] = a;
            auto [bt, bp] = b;
            auto A = 1.0 * (at - ap) / (at * (at + 1));
            auto B = 1.0 * (bt - bp) / (bt * (bt + 1));
            return A < B;
        };
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, decltype(Compare)> pq(Compare);
        double res = 0;
        for(auto& c : classes) {
            int p = c[0], t = c[1];
            if(p == t) res += 1;
            else pq.push({t, p});
        }
        while(extraStudents-- and !pq.empty()) {
            auto [t, p] = pq.top(); pq.pop();
            pq.push({t + 1, p + 1});
        }
        while(!pq.empty()) {
            auto [t, p] = pq.top(); pq.pop();
            res += 1.0 * p / t;
        }
        return res / classes.size();
    }
};