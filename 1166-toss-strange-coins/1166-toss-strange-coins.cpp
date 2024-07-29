class Solution {
    vector<vector<double>> dp;
    double helper(vector<double>& p, int t, int k) {
        if(k == p.size()) return t == 0;
        if(p.size() - k < t or t < 0) return 0;
        if(dp[k][t] != -1) return dp[k][t];
        
        return dp[k][t] = helper(p,t-1,k+1) * p[k] + helper(p,t,k+1)* (1-p[k]);
    }
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        dp = vector<vector<double>>(prob.size(), vector<double>(target + 1, -1));
        return helper(prob,target,0);
    }
};