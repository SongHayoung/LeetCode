class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int,int>> p, rp;
        int n = pairs.size();
        for(int i = 0; i < n; i++) {
            p.push_back({pairs[i][0], i});
            rp.push_back({pairs[i][1], i});
        }
        sort(begin(p), end(p));
        sort(begin(rp), end(rp));
        
        vector<int> dp(n, 1);
        int res = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; rp[j].first < p[i].first; j++) {
                dp[p[i].second] = max(dp[p[i].second], dp[rp[j].second] + 1);
                res = max(res, dp[p[i].second]);
            }
        }
        return res;
    }
};