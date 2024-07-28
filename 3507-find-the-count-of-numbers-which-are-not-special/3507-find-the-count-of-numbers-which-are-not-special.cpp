class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int sq = sqrt(r) + 1;
        vector<int> sieve(sq);
        for(int i = 2; i < sq; i++) {
            if(sieve[i]) continue;
            for(int j = i * i; j < sq; j += i) sieve[j] = 1;
        }
        int res = 0;
        for(int i = 2; i < sq; i++) {
            if(sieve[i]) continue;
            int po = i * i;
            if(l <= po and po <= r) res++;
        }
        return r - l + 1 - res;
    }
};