class Solution {
    bool helper(vector<int>& A, int m, int k) {
        m--;
        for(int i = 1, lst = A[0]; i < A.size() and m; i++) {
            if(A[i] - lst >= k) {
                m--;
                lst = A[i];
            }
        }
        return m == 0;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(begin(position), end(position));
        int l = 0, r = position.back(), res = l;
        while(l <= r) {
            int k = l + (r - l) / 2;
            bool ok = helper(position,m,k);
            if(ok) {
                l = k + 1;
                res = k;
            } else r = k - 1;
        }
        return res;
    }
};