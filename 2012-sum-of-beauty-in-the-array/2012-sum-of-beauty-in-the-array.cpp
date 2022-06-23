class Solution {
public:
    int sumOfBeauties(vector<int>& A) {
        int res = 0, n = A.size();
        vector<int> l(n), r(n);
        for(int i = 1, ma = A[0]; i < n; i++) {
            l[i] = ma;
            ma = max(ma, A[i]);
        }
        for(int i = n - 2, mi = A[n - 1]; i >= 0; i--) {
            r[i] = mi;
            mi = min(mi, A[i]);
        }
        for(int i = 1; i <= n - 2; i++) {
            if(l[i] < A[i] and A[i] < r[i]) res += 2;
            else if(A[i-1] < A[i] and A[i] < A[i+1]) res += 1;
        }
        return res;
    }
};