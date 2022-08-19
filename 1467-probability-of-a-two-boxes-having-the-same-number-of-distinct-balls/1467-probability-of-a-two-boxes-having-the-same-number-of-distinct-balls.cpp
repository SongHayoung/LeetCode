class Solution {
    double fac[44] = {};
    double fact(long long n) {
        if(n <= 1) return 1;
        if(fac[n]) return fac[n];
        return fac[n] = n * fact(n-1);
    }
    double total = 0, valid = 0;
    void helper(vector<int>& A, int p, int b1, int b2, int rem1, int rem2, double perm1, double perm2) {
        if(rem1 == 0 and rem2 == 0) {
            total += perm1 * perm2;
            valid += (b1 == b2) * perm1 * perm2;
        } else if(rem1 >= 0 and rem2 >= 0) {
            for(int a = 0, b = A[p]; b >= 0; a++, b--) {
                helper(A, p + 1, b1 + (a > 0), b2 + (b > 0), rem1 - a, rem2 - b, perm1 / fact(a), perm2 / fact(b));
            }
        }
    }
public:
    double getProbability(vector<int>& balls) {
        long long n = accumulate(begin(balls), end(balls), 0ll);
        helper(balls, 0, 0, 0, n / 2, n / 2, fact(n / 2), fact(n / 2));
        return 1. * valid / total;
    }
};