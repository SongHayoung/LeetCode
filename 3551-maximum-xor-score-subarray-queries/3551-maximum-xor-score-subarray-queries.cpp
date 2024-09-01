int dp[2020][2020], dpp[2020][2020];
class Solution {
    int helper(vector<int>& A, int l, int r) {
        if(dp[l][r] != -1) return dp[l][r];
        if(l == r) return dp[l][r] = dpp[l][r] = A[l];
        int& res = dp[l][r] = max({helper(A,l+1,r), helper(A,l,r-1)});
        dpp[l][r] = dpp[l+1][r] ^ dpp[l][r-1];
        res = max(res, dpp[l][r]);
        return res;
    }
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        memset(dp,-1,sizeof dp);
        memset(dpp,-1,sizeof dpp);
        vector<int> res;
        for(auto& q : queries) {
            res.push_back(helper(nums,q[0],q[1]));
        }
        return res;
    }
};