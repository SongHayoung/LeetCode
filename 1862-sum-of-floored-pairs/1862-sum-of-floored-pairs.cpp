class Solution {
public:
    int sumOfFlooredPairs(vector<int>& A) {
        sort(begin(A), end(A));
        int res = 0, n = A.size(), prevRes = 0, mod = 1e9 + 7;
        for(int i = 0, p, st = 0; i < n; st = ++i) {
            if(!i or A[i] != A[i-1]) {
                prevRes = 0;
                while(st < n) {
                    p = (A[st] / A[i]) + 1;
                    int nxt = lower_bound(begin(A) + st, end(A), A[i] * p) - begin(A);
                    prevRes = (prevRes + (nxt - st) * (p - 1)) % mod;
                    st = nxt;
                }
            }
            res = (res + prevRes) % mod;
        }
        
        
        return res;
    }
};