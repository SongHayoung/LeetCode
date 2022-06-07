class Solution {
public:
    int specialArray(vector<int>& A) {
        sort(begin(A), end(A));
        int l = 0, r = A.size();
        while(l <= r) {
            int m = l + (r - l) / 2;
            int count = end(A) - lower_bound(begin(A), end(A), m);
            if(m == count) return m;
            if(count > m) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};