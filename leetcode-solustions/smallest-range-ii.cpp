class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int res = A.back() - A.front();

        for (int i = 0; i < A.size() - 1; i++) {
            int hi = max(A.back() - K, A[i] + K);
            int lo = min(A.front() + K, A[i + 1] - K);
            res = min(res, hi - lo);
        }

        return res;
    }
};
