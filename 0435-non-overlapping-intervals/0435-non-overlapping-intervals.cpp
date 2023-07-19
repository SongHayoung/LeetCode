class Solution {
    int dp[100000];
    int helper(vector<vector<int>>& I, int p, int ed) {
        if(p == I.size()) return 0;
        if(dp[p] != -1) return dp[p];
        int& res = dp[p];
        res = helper(I,p+1,ed) + 1;
        if(ed <= I[p][0]) {
            vector<int> tmp{I[p][1],INT_MIN};
            int np = lower_bound(I.begin() + p, I.end(), tmp) - I.begin();
            res = min(res, helper(I,np, I[p][1]) + np - p - 1);
        }
        return res;
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& I) {
        sort(begin(I), end(I));
        memset(dp,-1,sizeof(dp));
        
        return helper(I,0,INT_MIN);
    }
};