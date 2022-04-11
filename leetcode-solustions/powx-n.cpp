class Solution {
public:
    double myPow(double x, int n) {
        long N = n < 0 ? -(long)n : n;
        double res = 1;
        while(N) {
            res *= N & 1 ? x : 1;
            N >>= 1;
            x *= x;
        }
        return n < 0 ? 1 / res : res;
    }
};
