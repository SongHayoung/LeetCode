class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), m = costs[0].size();
        vector<int> dp(m,0);
        for(auto& c : costs) {
            vector<pair<int,int>> best;
            for(int j = 0; j < m; j++) {
                best.push_back({dp[j],j});
                sort(begin(best),end(best));
                if(best.size() > 2) best.pop_back();
            }
            for(int j = 0; j < m; j++) {
                dp[j] = c[j] + (best[0].second == j ? best[1].first : best[0].first);
            }
        }
        return *min_element(begin(dp),end(dp));
    }
};