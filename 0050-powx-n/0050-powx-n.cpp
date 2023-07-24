class Solution {
    double helper(double x, long long n) {
        if(n == 0) return 1;
        double res = helper(x, n>>1);
        res = (res * res);
        if(n & 1) return res * x;
        return res;
    }
public:
    double myPow(double x, int n) {
        bool sign = (n >= 0);
        long long N = n;
        N = abs(N);
        double res = helper(x, N);
        return sign ? res : 1 / res;
    }
};