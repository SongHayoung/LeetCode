long long mod = 1e9 + 7;
class Solution {
    long long helper(int n) {
        if(n == 0) return 1;
        if(n < 0) return 0;
        long long res = 0;
        while(n > 0) {
            res = (res + 1 + n / 2) % mod;
            n -= 6;
        }
        return res + (n == 0);
    }
public:
    int numberOfWays(int n) {
        return (helper(n) + helper(n-4) + helper(n-8)) % mod;
    }
};