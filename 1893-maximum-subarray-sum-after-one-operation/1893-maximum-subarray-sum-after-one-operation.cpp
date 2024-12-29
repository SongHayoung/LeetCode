class Solution {
public:
    int maxSumAfterOperation(vector<int>& A) {
        int n = A.size();
        vector<int> pre(n), suf(n);
        for(int i = 0; i < n; i++) {
            pre[i] = max(0,A[i]);
            if(i) pre[i] = max(pre[i], pre[i-1] + A[i]);
        }
        for(int i = n - 1; i >= 0; i--) {
            suf[i] = max(0, A[i]);
            if(i + 1 < n) suf[i] = max(suf[i], suf[i+1] + A[i]);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            int now = A[i] * A[i];
            if(i) now += pre[i-1];
            if(i + 1 < n) now += suf[i+1];
            res = max(res, now);
        }
        return res;
    }
};