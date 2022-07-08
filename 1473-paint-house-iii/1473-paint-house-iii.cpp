class Solution {
    int dp[101][23][101];
    int helper(vector<int>& h, vector<vector<int>>& c, int t, int cur, int p) {
        if(t < 0) return 987654321;
        if(cur == h.size()) {
            return t ? 987654321 : 0;
        }
        if(dp[cur][p][t] != -1) return dp[cur][p][t];
        int& res = dp[cur][p][t] = INT_MAX;
        if(h[cur] == 0) {
            for(int i = 0; i < c[cur].size(); i++) {
                res = min(res, helper(h, c, t - (p != (i+1)), cur + 1, i+1) + c[cur][i]);
            }
        } else {
            res = helper(h,c, t - (h[cur] != p), cur + 1, h[cur]);
        }
        return res;
    }
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int res = helper(houses, cost, target, 0, 22);
        if(res >= 987654321) return -1;
        return res;
    }
};