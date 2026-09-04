class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n = units.size(), m = units[0].size();
        if(m == 1) {
            long long res = 0;
            for(auto& u : units) res += u[0];
            return res;
        }
        vector<pair<long long, long long>> S;
        for(auto& u : units) {
            sort(begin(u), end(u));
            S.push_back({u[1],u[0]});
        }
        sort(rbegin(S), rend(S));
        vector<long long> picks{{S.back().first, S.back().second}};
        S.pop_back();
        long long res = 0;
        for(auto& [a,b] : S) {
            picks.push_back(b);
            res += a;
        }
        res += *min_element(begin(picks), end(picks));
        return res;
    }
};