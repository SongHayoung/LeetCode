class Solution {
public:
    long long maxNumber(long long n) {
        long long lg2 = log2(n);
        return (1ll<<lg2) - 1;
    }
};