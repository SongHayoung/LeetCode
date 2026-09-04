vector<int> primes;
bool done = false;
class Solution {
    void init() {
        if(done) return;
        int n = 2e5;
        vector<int> sieve(n+1);
        for(long long i = 2; i <= n; i++) {
            if(sieve[i]) continue;
            primes.push_back(i);
            for(long long j = i * i; j <= n; j += i) sieve[j] = 1;
        }
    }
public:
    int minOperations(vector<int>& nums) {
        init();
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            int lb = lower_bound(primes.begin(), primes.end(),nums[i]) - begin(primes);
            if(i&1) {
                if(primes[lb] == nums[i]) res += (nums[i] == 2 ? 2 : 1);
            } else {
                res += primes[lb] - nums[i];
            }
            
        }
        return res;
    }
};