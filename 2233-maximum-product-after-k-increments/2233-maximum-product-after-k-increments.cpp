class Solution {
    int mod = 1e9 + 7;
    long modpow(int n, int x) {
        if(x <= 1) return !x ? 1 : n;
        long res = modpow(n,x>>1);
        res = (res * res) % mod;
        if(x & 1) res = (res * n) % mod;
        return res;
    }
public:
    int maximumProduct(vector<int>& A, int k) {
        sort(begin(A), end(A));
        long long sum = 0, pos = 0, left = 0, req, ext, res;
        
        for(long long i = 0; i < A.size(); i++) {
            req = A[i] * i - sum;
            if(req <= k) {
                pos = i;
                left = k - req;
            } else break;
            sum += A[i];
        }
        
        ext = left / (pos + 1);
        left -= ext * (pos + 1);
        res = (modpow(A[pos] + ext + 1, left) * modpow(A[pos] + ext, pos + 1 - left)) % mod;
        
        for(int i = pos + 1; i < A.size(); i++)
            res = (res * A[i]) % mod;
        
        return res;
    }
};