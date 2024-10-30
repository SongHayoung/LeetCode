class Solution {
    void lis(vector<int>& lis, int n) {
        auto it = lower_bound(lis.begin(), lis.end(), n);
        if(it == end(lis)) lis.push_back(n);
        else *it = n;
    }
public:
    int minimumMountainRemovals(vector<int>& A) {
        int n = A.size(), res = INT_MAX;
        vector<int> l, r, dp(n);
        for(int i = 0; i < n; i++) {
            lis(l,A[i]);
            dp[i] = l.size();
        }
        for(int i = n - 1; i >= 0; i--) {
            lis(r,A[i]);
            if(dp[i] > 1 and r.size() > 1)
                res = min(res, n - (dp[i] + (int)r.size() - 1));
        }
        return res;
    }
};