class Solution {
    long extraSpaceSize(long space) {
        return space >= 0 ? space : (-space + 1) * space / 2;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        long l(0), r(INT_MAX), m, res(1);
        while(l <= r) {
            m = (l + r)>>1;

            if(m * m + extraSpaceSize(index + 1 - m) + extraSpaceSize(n - index - m) <= maxSum) {
                res = max(res, m);
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return res;
    }
};