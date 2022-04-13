class Solution {
    int top(vector<int> &A, int l, int r) {
        while(l < r) {
            int m = (l + r) / 2;
            if(A[m] > A[m + 1]) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        int l = 0, r = n-1;
        return top(A,l,r);
    }
};
