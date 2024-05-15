class Solution {
    int helper(int x, vector<int>& A, vector<int>& B, vector<int>& C) {
        int l = 0, r = INT_MAX, res = 0;
        auto can = [&](int m) {
            long long cost = 0;
            for(int i = 0; i < A.size() and cost <= x; i++) {
                long long tool = max(0ll, 1ll * A[i] * m - B[i]);
                cost += C[i] * tool;
            }
            return cost <= x;
        };
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = can(m);
            if(ok) {
                l = m + 1;
                res = m;
            } else r = m - 1;
        }
        return res;
    }
public:
    int maxNumberOfAlloys(int n, int k, int x, vector<vector<int>>& A, vector<int>& B, vector<int>& C) {
        int res = 0;
        for(int i = 0; i < k; i++) {
            res = max(res, helper(x,A[i],B,C));
        }
        return res;
    }
};