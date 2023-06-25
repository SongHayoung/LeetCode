class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        if(num1 == 0) return 0;
        for(long long i = 1; i < 60; i++) {
            long long x = num1 - i * num2;
            if(x < 0) return -1;
            if(__builtin_popcountll(x) <= i and x >= i) return i;
        }
        return -1;
    }
};
