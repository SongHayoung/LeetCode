class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> sieve(n+1, true);
        sieve[0] = sieve[1] = 0;
        for(long long i = 2; i <= n; i++) {
            if(!sieve[i]) continue;
            for(long long j = i * i; j <= n; j += i) sieve[j] = false;
        }
        vector<vector<int>> res;
        for(int i = 2; 2 * i <= n; i++) {
            int j = n - i;
            if(i > j) break;
            if(!sieve[i] or !sieve[j]) continue;
            res.push_back({i,j});
        }
        return res;
    }
};