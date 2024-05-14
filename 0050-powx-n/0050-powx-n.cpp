class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(n == 0) return 1;
        if(x == 1) return 1;
        if(x == 1) return n & 1 ? -1 : 1;
        double res = 1.;
        long long N = n;
        if(N < 0) N = -N, x = 1. / x;
        while(N) {
            if(N & 1) res = res * x;
            x = x * x;
            N /= 2;
        }
        return res;
    }
};