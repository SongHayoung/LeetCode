class Solution {
    int helper(vector<int>& A, vector<int>& B, int p, int q) {
        auto func = [&](int i) {
            return p * A[i] + q * B[i] + i;
        };
        int mi = func(0), ma = func(0), n = A.size();
        for(int i = 1; i < n; i++) {
            mi = min(mi, func(i));
            ma = max(ma, func(i));
        }
        return ma - mi;
    }
public:
    int maxAbsValExpr(vector<int>& A, vector<int>& B) {
        int res = INT_MIN;
        res = max(res, helper(A,B,1,1));
        res = max(res, helper(A,B,1,-1));
        res = max(res, helper(A,B,-1,-1));
        res = max(res, helper(A,B,-1,1));
        return res;
    }
};