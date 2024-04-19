
class Solution {
public:
    int reverse(int x) {
        long long sign = 1, res = 0;
        if(x < 0) sign = -1;
        while(x) {
            int val = (x % 10) * sign;
            res = res * 10 + val;
            x /= 10;
        }
        return INT_MIN <= res * sign and res * sign <= INT_MAX ? res * sign : 0;
    }
};