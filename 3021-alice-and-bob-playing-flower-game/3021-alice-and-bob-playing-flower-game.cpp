class Solution {
public:
    long long flowerGame(int n, int m) {
        long long even = m / 2;
        long long odd = m - even;
        long long on = n - (n / 2);
        return on * even + (n - on) * odd;
    }
};