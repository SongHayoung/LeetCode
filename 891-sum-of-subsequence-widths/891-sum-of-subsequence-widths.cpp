class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(begin(A), end(A));
        long long res = 0, mod = 1e9 + 7, n = A.size();
        for(long long i = 0, p = 1; i < n; i++, p = p*2%mod) {
            res = (res + A[i] * p) % mod;
        }
        for(long long i = n - 1, p = 1; i >= 0; i--, p = p*2%mod) {
            res = (res - A[i] * p) % mod;
            res = (res + mod) % mod;
        }
        return res;
    }
};