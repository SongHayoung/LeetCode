// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n, m, res = INT_MAX;
        while(l <= r) {
            m = l + (r-l)/2;
            if(isBadVersion(m)) {
                res = min(res, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res;
    }
};