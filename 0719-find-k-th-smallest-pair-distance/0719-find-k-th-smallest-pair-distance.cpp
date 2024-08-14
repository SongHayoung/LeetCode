class Solution {
    bool helper(vector<int>& A, int k, int m) {
        int c = 0;
        for(int i = 0, j = 0; i < A.size() and c < k; i++) {
            while(j < A.size() and A[j] - A[i] <= m) j++;
            c += j - i - 1;
        }
        return c >= k;
    }
public:
    int smallestDistancePair(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int l = 0, r = 1e6, res = r;
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(A,k,m);
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};