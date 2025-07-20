class Solution {
    int sum(int n) {
        int res = 0;
        while(n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    int mul(int n) {
        int res = 1;
        while(n) {
            res *= n % 10;
            n /= 10;
        }
        return res;
    }
public:
    bool checkDivisibility(int n) {
        return n % (sum(n) + mul(n)) == 0;
    }
};