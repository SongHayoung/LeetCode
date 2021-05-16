class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        unordered_map<int, vector<vector<int>>> dp;
        sort(begin(c), end(c));
        c.erase(upper_bound(begin(c), end(c), t), end(c));
        for(auto& n : c) {
            dp[n].push_back(vector<int>{n});
            for(int i = 1; i <= t - n; i++) {
                if(!dp.count(i)) continue;
                for(auto& vec : dp[i]) {
                    vector<int> tmp(begin(vec), end(vec));
                    tmp.push_back(n);
                    dp[i + n].push_back(tmp);
                }
            }
        }
        return dp[t];
    }
};
