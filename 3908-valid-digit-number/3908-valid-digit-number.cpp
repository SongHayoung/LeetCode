class Solution {
public:
    bool validDigit(int n, int x) {
        bool has = false;
        while(n >= 10) {
            has |= n % 10 == x;
            n /= 10;
        }
        return has and n != x;
    }
};