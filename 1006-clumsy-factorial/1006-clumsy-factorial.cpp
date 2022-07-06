class Solution {
public:
    int clumsy(int n, int sign = 1) {
        if(n == 3) return sign * 3 * 2 / 1;
        if(n == 2) return sign * 2 * 1;
        if(n == 1) return sign * 1;
        if(n == 0) return 0;
        return sign * n * (n - 1) / (n - 2) + (n - 3) + clumsy(n - 4, -1);
    }
};