
class Solution {
public:
    int largestPrime(int n) {
        if(n == 1) return 0;
        int sq = sqrt(n) + 1;
        vector<int> sieve(n + 1);
        for(int i = 2; i <= sq; i++) {
            if(sieve[i]) continue;
            for(int j = i * i; j <= n; j += i) sieve[j] = 1;
        }
        int res = 0;
        for(int i = 2, sum = 0; sum <= n and i <= n; i++) {
            if(sieve[i]) continue;
            sum += i;
            if(sum <= n and !sieve[sum]) res = sum;
        }
        return res;
    }
};