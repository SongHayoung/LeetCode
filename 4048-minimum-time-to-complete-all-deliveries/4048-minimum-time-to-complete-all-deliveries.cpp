class Solution {
    long long helper(vector<int> &A, vector<int> &B, long long t, long long l) {
        long long t1 = t / B[0], t2 = t / B[1], tl = t / l;
        long long a = t2 - tl, b = t1 - tl, c = t - t1 - t2 + tl;
        return max(0ll, A[0] - a) + max(0ll, A[1] - b) <= c;
    }

public:
    long long minimumTime(vector<int> &d, vector<int> &r) {
        long long lcm = 1ll * r[0] / __gcd(r[0], r[1]) * r[1];
        long long le = 1, ri = 2e18, res = 2e18;
        while (le <= ri) {
            long long m = le + (ri - le) / 2;
            bool ok = helper(d, r, m, lcm);
            if (ok) {
                res = m;
                ri = m - 1;
            } else le = m + 1;
        }
        return res;
    }
};