class Solution {
public:
    int smallestNumber(int n) {
        int res = 1;
        while(res <= n) res *= 2;
        return res - 1;
    }
};