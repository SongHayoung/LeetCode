class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        if(n > m) return findMedianSortedArrays(B,A);
        int tot = n + m, l = 0, r = n;
        while(l <= r) {
            int m1 = l + (r - l) / 2;
            int m2 = tot / 2 - m1;
            if(m1 and A[m1-1] > B[m2]) r = m1 - 1;
            else if(m1 != n and A[m1] < B[m2-1]) l = m1 + 1;
            else {
                int r = INT_MAX;
                if(m1 != n) r = min(r, A[m1]);
                if(m2 != m) r = min(r, B[m2]);
                if(tot & 1) return r;
                int l = INT_MIN;
                if(m1) l = max(l, A[m1-1]);
                if(m2) l = max(l, B[m2-1]);
                return (l + r) / 2.;
            }
        }
        return -1;
    }
};