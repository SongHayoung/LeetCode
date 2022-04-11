class Solution {
    int conversion(int n) {
        long res = 0, i = 1;
        while(n) {
            res = res + (n%9) * i;
            n/=9;
            i *= 10;
        }
        return res;
    }
public:
    int newInteger(int n) {
        return conversion(n);
    }
};