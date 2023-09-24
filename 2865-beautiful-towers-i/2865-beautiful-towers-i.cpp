class Solution {
public:
    long long maximumSumOfHeights(vector<int>& A) {
        int n = A.size();
        long long res = 0;
        auto left = [&](long long best, int p) {
            long long res = 0;
            for(int i = p; i >= 0; i--) {
                best = min(best, 1ll * A[i]);
                res += best;
            }
            return res;
        };
        auto right = [&](long long best, int p) {
            long long res = 0;
            for(int i = p; i < n; i++) {
                best = min(best, 1ll * A[i]);
                res += best;
            }
            return res;
        };
        for(int i = 0; i < n; i++) {
            res = max(res, A[i] + left(A[i],i-1) + right(A[i],i+1));
        }
        return res;
    }
};

