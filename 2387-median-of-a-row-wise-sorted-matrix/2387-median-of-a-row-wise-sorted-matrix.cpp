class Solution {
public:
    int matrixMedian(vector<vector<int>>& A) {
        long long l = 0, r = INT_MAX, res = 0;
        long long med = A.size() * A[0].size() / 2 + 1;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            long long now = 0;
            for(int i = 0; i < A.size(); i++) {
                now += end(A[i]) - lower_bound(begin(A[i]), end(A[i]), m);
            }
            if(now >= med) {
                res = max(res, m);
                l = m + 1;
            } else r = m - 1;
        }
        return res;
    }
};