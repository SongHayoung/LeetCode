class Solution {
public:
    int totalMoney(int n) {
        int q = n / 7, r = n % 7;
        return 28 * q + q * (q - 1) / 2 * 7 + q * r + r * (r + 1) / 2;
    }
};