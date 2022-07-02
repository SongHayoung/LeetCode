class Solution {
public:
    int minOperations(int n) {
        int c = (n + 1) / 2;
        return c * (2 * n - 1 - (n & 1 ? n : n - 1)) / 2;
    }
};