class Solution {
public:
    long long maxNumber(long long n) {
        return (1ll<<((int)log2(n))) - 1;
    }
};