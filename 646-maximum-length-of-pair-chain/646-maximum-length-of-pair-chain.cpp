class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<array<int,3>> p, rp;
        int n = pairs.size();
        for(int i = 0; i < n; i++) {
            p.push_back({pairs[i][0], pairs[i][1], i});
            rp.push_back({pairs[i][1], pairs[i][0], i});
        }
        sort(begin(p), end(p));
        sort(begin(rp), end(rp));
        
        vector<int> dp(n, 1);
        int res = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; rp[j][0] < p[i][0]; j++) {
                dp[p[i][2]] = max(dp[p[i][2]], dp[rp[j][2]] + 1);
                res = max(res, dp[p[i][2]]);
            }
        }
        return res;
    }
};