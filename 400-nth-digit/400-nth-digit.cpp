class Solution {
public:
    int findNthDigit(int n) {
        long start = 1;
        int len = 1;
        for(; n > ((start<<3) + start) * len; start = (start<<3) + (start<<1), len++) {
            n -= (((start<<3) + start) * len);
        }
        n--;
        return to_string(start + n / len)[n % len] & 0b1111;
    }
};