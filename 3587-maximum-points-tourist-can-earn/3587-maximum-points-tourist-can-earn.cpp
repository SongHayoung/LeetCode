class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<int> dp(n);
        for(int i = 0; i < k; i++) {
            vector<int> dpp(n);
            for(int u = 0; u < n; u++) {
                for(int v = 0; v < n; v++) {
                    if(u == v) dpp[v] = max(dpp[v], dp[u] + stayScore[i][u]);
                    else dpp[v] = max(dpp[v], dp[u] + travelScore[u][v]);
                }
            }
            swap(dp,dpp);
        }
        return *max_element(begin(dp), end(dp));
    }
};
