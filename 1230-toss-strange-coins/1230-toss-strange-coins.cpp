class Solution {
    vector<vector<double>> dp;
    double helper(vector<double>& p, int t, int k) {
        if(k == p.size()) return t == 0 ? 1.0 : 0.0;
        if(p.size() - k < t) return 0;
        if(t < 0) return 0;
        if(dp[k][t] != -1) return dp[k][t];
        
        auto& res = dp[k][t] = 0;
        
        double fo = helper(p,t-1,k+1) * p[k], ba = helper(p,t,k+1) * (1-p[k]);
        
        res = fo + ba;
        
        return res;
    }
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        dp = vector<vector<double>>(prob.size(), vector<double>(target + 1, -1));
        return helper(prob,target,0);
    }
};