class Solution {
public:
    int addDigits(int& n) {
        return n ? 1 + (n - 1) % 9: 0;
    }
};
