class Solution {
public:
    vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
        vector<pair<long long, long long>> S;
        for(int i = 0; i < monsters.size(); i++) {
            S.push_back({monsters[i], coins[i]});
        }
        sort(begin(S), end(S));
        for(int i = 1; i < S.size(); i++) {
            S[i].second += S[i-1].second;
        }
        vector<long long> res;
        long long inf = 1e18;
        for(auto& h : heroes) {
            auto p = upper_bound(begin(S), end(S), make_pair(1ll * h,inf)) - begin(S) - 1;
            res.push_back(p == -1 ? 0 : S[p].second);
        }
        return res;
    }
};