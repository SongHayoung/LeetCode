class Solution {
public:
    int minimumSwaps(vector<int>& A) {
        int mi = INT_MAX, mip = -1, ma = INT_MIN, map = -1, n = A.size(), res = 0;
        for(int i = 0; i < n; i++) {
            if(mi > A[i]) {
                mi = A[i];
                mip = i;
            }
        }
        res += mip;
        while(mip) {
            swap(A[mip], A[--mip]);
        }
        for(int i = 0; i < n; i++) {
            if(ma <= A[i]) {
                ma = A[i];
                map = i;
            }
        }
        res += (n - map - 1);
        return res;
    }
};