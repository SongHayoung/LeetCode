class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> A;
        for(int i = 0; i < ranges.size(); i++) {
            int l = max(0, i - ranges[i]);
            int r = min(n, i + ranges[i]);
            A.push_back({l,r});
        }
        sort(begin(A), end(A), [&](auto a, auto b) {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        if(A[0].first != 0) return -1;
        int res = 1, best = A[0].second, ma = best;
        for(auto& [l,r] : A) {
            if(l > best) {
                res++;
                best = ma;
            }
            if(l > best) return -1;
            ma = max(ma, r);
        }
        if(best != n) res++, best = ma;
        return best == n ? res : -1;
    }
};