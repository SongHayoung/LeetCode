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
            else if(m1 < n and A[m1] < B[m2-1]) l = m1 + 1;
            else {
                int x = INT_MAX, y = INT_MIN;
                if(m1 != n) x = min(x, A[m1]);
                if(m2 != m) x = min(x, B[m2]);
                if(tot & 1) return x;
                if(m1) y = max(y, A[m1-1]);
                if(m2) y = max(y, B[m2-1]);
                return (x + y) / 2.;
            }
        }
        return -1;
    }
};