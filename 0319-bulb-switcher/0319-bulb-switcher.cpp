class Solution {
public:
    int bulbSwitch(int n) {
        int l = 0, r = n, res = 0;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = m * m <= n;
            if(ok) {
                res = m;
                l = m + 1;
            } else r = m - 1;
        }
        return res;
    }
};