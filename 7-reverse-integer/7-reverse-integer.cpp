class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while(x) {
            long cur = (res * 10) + x % 10;
            if ((cur / 10) != res || cur > INT_MAX || cur < INT_MIN) return 0;
            res = cur;
            x/=10;
        }
        return res;
    }
};