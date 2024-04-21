class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        if(n > m) return findMedianSortedArrays(B,A);
        int l = 0, r = n, tot = n + m;
        while(l <= r) {
            int m1 = l + (r - l) / 2;
            int m2 = tot / 2 - m1;
            if(m1 and A[m1-1] > B[m2]) r = m1 - 1;
            else if(m1 != n and A[m1] < B[m2-1]) l = m1 + 1;
            else {
                int ri = INT_MAX;
                if(m1 != n) ri = min(ri, A[m1]);
                if(m2 != m) ri = min(ri, B[m2]);
                if(tot & 1) return ri;
                int le = INT_MIN;
                if(m1) le = max(le, A[m1-1]);
                if(m2) le = max(le, B[m2-1]);
                return 1. * (le + ri) / 2.;
            }
        }
        return -1;
    }
};
