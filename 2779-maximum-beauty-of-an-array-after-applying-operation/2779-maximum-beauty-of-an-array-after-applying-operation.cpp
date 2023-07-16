class Solution {
public:
    int maximumBeauty(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int l = 0, r = 0, n = A.size(), res = 0;
        while(r < n) {
            while(r < n and A[l] + 2 * k >= A[r]) {
                res = max(res, r - l + 1);
                r += 1;
            }
            l += 1;
        }
        return res;
    }
};