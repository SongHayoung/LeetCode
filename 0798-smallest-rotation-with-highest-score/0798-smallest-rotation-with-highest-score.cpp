class Solution {
public:
    int bestRotation(vector<int>& A) {
        vector<int> pre(A.size() + 1);
        auto udt = [&](int l, int r) {
            pre[l] += 1;
            pre[r+1] -= 1;
        };
        int n = A.size();
        for(int i = 0; i < A.size(); i++) {
            int l = A[i], r = n;
            if(l <= i) {
                udt(0,i-l);
                l = i + 1;
            }
            if(l <= r) {
                udt(i + 1,n - (l - i));
            }
        }
        
        
        int res = 0;
        for(int i = 0; i < pre.size(); i++) {
            if(i) pre[i] += pre[i-1];
            if(pre[res] < pre[i]) res = i;
        }
        return res;
    }
};