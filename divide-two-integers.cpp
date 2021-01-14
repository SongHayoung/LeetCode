class Solution {
private:
    long shift(long &dividend, long shiftedDivisor, int shifted) {
        if(dividend < shiftedDivisor)
            return 0;
        long ret = shift(dividend, shiftedDivisor << 1, shifted + 1);
        if(dividend >= shiftedDivisor) {
            dividend -= shiftedDivisor;
            return ret + pow(2, shifted);
        }
        return ret;
    }
public:
    int divide(int dividend, int divisor) {
        long shiftedDivisor = divisor;
        long positiveDividend = dividend;

        if(shiftedDivisor < 0) shiftedDivisor *= -1;
        if(positiveDividend < 0) positiveDividend *= -1;

        if(!divisor)
            return INT_MAX;

        return min((long)INT_MAX, (divisor < 0 && dividend < 0) || (divisor > 0 && dividend > 0) ? shift(positiveDividend, shiftedDivisor, 0) : -1 * shift(positiveDividend, shiftedDivisor, 0));
    }
};
