class Solution {
public:
    int kthDigit(long long k) {
        long long remain = k;
        long long digit = 1, base = 0;
        long long count = 9;
        while(remain > count) {
            remain -= count;
            digit++;
            base = digit == 2 ? 1 : base * 10;
            count = (long long)9 * digit * base * 10;
        }
        if(digit == 1) return remain;
        remain--;
        long long block = base + remain / (digit * 10);
        long long inside = remain % (digit * 10);
        long long idx = inside / digit;
        long long pos = inside % digit;
        long long num = block * 10 + (block & 1 ? 9 - idx : idx);
        return to_string(num)[pos] - '0';
    }
};