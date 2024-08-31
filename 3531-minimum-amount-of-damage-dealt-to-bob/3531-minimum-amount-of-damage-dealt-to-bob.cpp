class Solution {
public:
    long long minDamage(int k, vector<int>& capacity, vector<int>& health) {
        long long res = 0, op = 0;
        vector<array<long double, 3>> S;
        for(int i = 0; i < capacity.size(); i++) {
            long double cnt = (health[i] + k - 1) / k, mul = cnt * capacity[i];
            S.push_back({capacity[i] / cnt, 1. * capacity[i], cnt});
        }
        sort(rbegin(S), rend(S));
        for(auto& [_, cap, cnt] : S) {
            op += cnt;
            res += cap * op;
        }
        return res;
    }
};
