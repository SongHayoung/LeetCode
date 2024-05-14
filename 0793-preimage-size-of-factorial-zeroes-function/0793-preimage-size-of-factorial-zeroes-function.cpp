class Solution {
    long long calc(long long m) {
        long long res = 0;
        while(m) {
            res += m / 5;
            m /= 5;
        }
        return res;
    }
    long long helper(int x) {
        long long l = 0, r = LLONG_MAX - 1, res = r;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = calc(m) >= x;
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
public:
    int preimageSizeFZF(int k) {
        return helper(k+1) - helper(k);
    }
};