class Solution {
public:
    long long maxNumber(long long n) {
        long long bit = -1;
        while(n) {
            bit++;
            n /= 2;
        }
        return (1ll<<bit) - 1;
    }
};