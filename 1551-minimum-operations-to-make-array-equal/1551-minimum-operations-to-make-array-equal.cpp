class Solution {
public:
    int minOperations(int n) {
        return (n + 1) / 2 * (2 * n - 1 - (n & 1 ? n : n - 1)) / 2;
    }
};