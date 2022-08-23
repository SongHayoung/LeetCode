class Solution {
public:
    int maxValueAfterReverse(vector<int>& A) {
        int sum = 0, rev = 0, ma = -1e5, mi = 1e5, n = A.size();
        for(int i = 0; i < n - 1; i++) {
            sum += abs(A[i] - A[i + 1]);
            rev = max(rev, abs(A[0] - A[i + 1]) - abs(A[i] - A[i + 1]));
            rev = max(rev, abs(A[n - 1] - A[i]) - abs(A[i] - A[i + 1]));
            mi = min(mi, max(A[i], A[i + 1]));
            ma = max(ma, min(A[i], A[i + 1]));
        }
        return sum + max(rev, (ma - mi) * 2);
    }
};