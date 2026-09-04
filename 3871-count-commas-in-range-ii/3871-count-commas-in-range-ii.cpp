
class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;
        for(long long i = 1000, op = 1; i <= n; i = i * 1000, op++) {
            long long cnt = min(i * 1000 - 1, n) - i + 1;
            res += op * cnt;
        }
        return res;
    }
};