class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size(), m = costs[0].size();
        vector<int> dp(m);
        auto who = [](vector<pair<int,int>>& A, int p) {
            for(auto& [a,b] : A) {
                if(b != p) return a;
            }
            return 0;
        };
        for(int i = 0; i < n; i++) {
            vector<pair<int, int>> best;
            for(int i = 0; i < m; i++) {
                best.push_back({dp[i],i});
                sort(begin(best), end(best));
                if(best.size() > 2) best.pop_back();
            }
            for(int j = 0; j < m; j++) {
                dp[j] = costs[i][j] + who(best,j);
            }
        }
        
        return *min_element(begin(dp), end(dp));
    }
};