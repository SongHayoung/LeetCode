class Solution {
public:
    int sumOfFlooredPairs(vector<int>& A) {
        sort(begin(A), end(A));
        int res = 0, n = A.size(), prevRes = 0, mod = 1e9 + 7;
        for(int i = 0; i < n; i++) {
            if(!i or A[i] != A[i-1]) {
                int st = i, p; prevRes = 0;
                while(st < n) {
                    p = (A[st] / A[i]) + 1;
                    int nxt = lower_bound(begin(A) + st, end(A), A[i] * p) - begin(A) - 1;
                    prevRes = (prevRes + (nxt - st + 1) * (p - 1)) % mod;
                    st = nxt + 1;
                }
            }
            res = (res + prevRes) % mod;
        }
        
        
        return res;
    }
};