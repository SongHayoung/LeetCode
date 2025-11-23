class Solution {
    int isPrime(int x) {
        int sq = sqrt(x);
        for(int i = 2; i <= sq; i++) if(x % i == 0) return false;
        return true;
    }
public:
    int minNumberOfPrimes(int n, int m) {
        vector<int> primes;
        for(int i = 2; i <= n and primes.size() < m; i++) {
            if(isPrime(i)) primes.push_back(i);
        }
        vector<long long> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(auto& p : primes) {
                if(i < p) break;
                dp[i] = min(dp[i], dp[i-p] + 1);
            }
        }
        
        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};