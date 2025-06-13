class Solution {
    bool helper(vector<int>& A, int d, int p) {
        for(int i = A.size() - 1; i > 0 and p > 0; i--) {
            if(A[i] - A[i-1] <= d) {
                p -= 1;
                i -= 1;
            }
        }
        return p <= 0;
    }
public:
    int minimizeMax(vector<int>& A, int p) {
        sort(begin(A), end(A));
        int l = 0, r = A.back() - A.front(), res = r;
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(A,m,p);
            if(ok) {
                r = m - 1;
                res = min(res, m);
            } else l = m + 1;
        }
        return res;
    }
};