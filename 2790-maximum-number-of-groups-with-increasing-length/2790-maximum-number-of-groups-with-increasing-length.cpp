class Solution {
    bool helper(vector<int>& A, int k) {
        int need = 0, x = k;
        for(int i = A.size() - 1; i >= 0; i--,x = max(x - 1, 0)) {
            if(A[i] == x) continue;
            if(A[i] > x) {
                int now = A[i] - x;
                need = max(0, need - now);
            } else {
                need += x - A[i];
            }

        }
        return need == 0;
    }
public:
    int maxIncreasingGroups(vector<int>& A) {
        sort(begin(A), end(A));
        int l = 0, r = A.size(), res = l;
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(A, m);
            if(ok) {
                res = max(res, m);
                l = m + 1;
            } else r= m - 1;
        }
        return res;
    }
};