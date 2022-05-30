class Solution {
    unordered_map<int, int> dp;
    int makeKey(vector<int>& needs) {
        int res = 0;
        for(int i = 0; i < needs.size(); i++) {
            res += (needs[i]<<(i*4));
        }
        return res;
    }
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int key = makeKey(needs);
        if(dp.count(key)) return dp[key];
        int result = inner_product(price.begin(), price.end(), needs.begin(), 0);
        for (vector<int>& offer : special) {
            vector<int> r = can(needs, offer);
            if (r.empty()) continue;
            result = min(result, offer.back() + shoppingOffers(price, special, r));
        }
        return dp[key] = result;
    }
    vector<int> can(const vector<int>& needs, const vector<int>& offer) {
        vector<int> r(needs.size(), 0);
        for (int i = 0, n = needs.size(); i < n; ++i) {
            if (offer[i] > needs[i]) return vector<int>();
            r[i] = needs[i] - offer[i];
        }
        return r;
    }
};