class Solution {
public:
    long long countFairPairs(vector<int>& A, int lower, int upper) {
        sort(begin(A), end(A));
        long long res = 0;
        for(int i = 0; i < A.size(); i++) {
            auto lo = lower_bound(begin(A) + i + 1, end(A), lower - A[i]);
            auto hi = upper_bound(begin(A) + i + 1, end(A), upper - A[i]);
            res += hi - lo;
        }
        return res;
    }
};