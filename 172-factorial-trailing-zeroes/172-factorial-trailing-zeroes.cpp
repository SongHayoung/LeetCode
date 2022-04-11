class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0, powFive = 5;
        while(powFive <= n) {
            res += n / powFive;
            powFive *= 5;
        }
        return res;
    }
};