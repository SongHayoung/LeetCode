class Solution {
public:
    int findKthNumber(int n, int k) {
        long long res = 1;
        while(k != 1) {
            int count = 0;
            for(long long first = res, last = res + 1; first <= n; first *= 10, last *= 10) {
                count += (min(n + 1ll, last) - first);
            }
            if(count < k) {
                k -= count;
                ++res;
            } else {
                --k;
                res *= 10;
            }
        }
        return res;
    }
};