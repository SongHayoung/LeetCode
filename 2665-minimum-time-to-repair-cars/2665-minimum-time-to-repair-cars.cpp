class Solution {
    bool helper(vector<int>& A, int c, long long m) {
        for(int i = 0; i < A.size(); i++) {
            long long x = sqrt(m / A[i]);
            c -= x;
            if(c <= 0) break;
        }
        return c <= 0;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0, r = LLONG_MAX, res = LLONG_MAX;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = helper(ranks, cars, m);
            if(ok) {
                res = min(res, m);
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};