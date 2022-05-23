class Solution {
public:
    int trap(vector<int>& A) {
        int res = 0, l = 0, r = A.size() - 1, lma = A[0], rma = A[r];
        while(l < r) {
            if(A[l] < A[r]) {
                while(l < r and A[l] <= lma) {
                    res += lma - A[l++];
                }
                lma = A[l];
            } else {
                while(l < r and A[r] <= rma) {
                    res += rma - A[r--];
                }
                rma = A[r];
            }
        }
        return res;
    }
};