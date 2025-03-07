class Solution {

public:
    vector<int> closestPrimes(int left, int right) {
        vector<long long> sieve(1000001);
        vector<long long> primes;
        for(long long i = 2; i < 1000001; i++) {
            if(sieve[i]) continue;
            primes.push_back(i);
            for(long long j = i * i; j < 1000001; j += i) sieve[j] = true;
        }
        primes.push_back(INT_MAX);
        auto lb = lower_bound(begin(primes), end(primes), left) - begin(primes);
        vector<int> res = {-1,-1};
        for(int i = lb; i < primes.size() - 1; i++) {
            if(res[0] == -1) {
                if(primes[i + 1] <= right) res = {(int)primes[i], (int)primes[i+1]};
            } else {
                if(primes[i+1] > right) break;
                long long diff = res[1] - res[0];
                if(primes[i+1] - primes[i] < diff)  res = {(int)primes[i], (int)primes[i+1]}; 
            }
        }
       return res;
    }
};