long long meds[1<<13], szs[1<<13], dp[1<<13];
class Solution {
    bool bit(int a, int b) {
        return (a>>b) & 1;
    }
    void med(vector<vector<int>>& A, int g) {
        long long& sz = szs[g] = 0;
        long long& med = meds[g] = LLONG_MAX;
        for(int i = 0; i < A.size(); i++) {
            if(!bit(g,i)) continue;
            sz += A[i].size();
        }
        int t = (sz - 1) / 2, l = -1e9, r = 1e9;
        while(l <= r) {
            int m = l + (r - l) / 2, sum = 0;
            for(int i = 0; i < A.size(); i++) {
                if(!bit(g,i)) continue;
                sum += upper_bound(begin(A[i]), end(A[i]), m) - begin(A[i]);
            }
            if(sum > t) {
                r = m - 1;
                med = m;
            } else l = m + 1;
        }
    }
    long long helper(int mask) {
        if(dp[mask] != -1) return dp[mask];
        long long& res = dp[mask] = LLONG_MAX;
        for(int sub = (mask - 1) & mask; sub; sub = (sub - 1) & mask) {
            int g1 = mask ^ sub, g2 = sub;
            if(g2 < g1) break;
            res = min(res, helper(g1) + helper(g2) + szs[mask] + abs(meds[g1] - meds[g2]));
        }
        return res;
    }
public:
    long long minMergeCost(vector<vector<int>>& lists) {
        int n = lists.size();
        for(int i = 1; i < 1<<n; i++) med(lists,i);
        memset(dp,-1,sizeof dp);
        for(int i = 0; i < n; i++) dp[1<<i] = 0;
        dp[0] = 0;
        return helper((1<<n) - 1);
    }
};