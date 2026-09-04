class Solution {
    long long rev(int n) {
        long long res = 0;
        while(n) {
            res = res * 10 +  (n % 10);
            n /= 10;
        }
        return res;
    }
public:
    int mirrorDistance(int n) {
        return abs(n - rev(n));
    }
};