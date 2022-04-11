class Solution {
public:
    int smallestFactorization(int a) {
        if(a < 10)
            return a;
        int digit = 9;
        long res = 0, mul = 1;
        while(digit > 1) {
            while(!(a % digit)) {
                a/=digit;
                res += mul * digit;
                mul = (mul<<3) + (mul<<1);
                if(res > INT_MAX)
                    return 0;
            }
            digit--;
        }
        return a == 1 ? res : 0;
    }
};
