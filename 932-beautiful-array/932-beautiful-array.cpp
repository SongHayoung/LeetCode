class Solution {
    unordered_map<int, vector<int>> dp;
public:
    vector<int> beautifulArray(int n) {
        if(n == 1) return {1};
        if(dp.count(n)) return dp[n];
        auto odd = beautifulArray((n + 1) / 2);
        auto even = beautifulArray(n/2);
        vector<int> res;
        for(auto& o : odd) res.push_back(o * 2 - 1);
        for(auto& e : even) res.push_back(e * 2);
        return dp[n] = res;
    }
};