int sieve[111];
class Solution {
public:
    int maximumPrimeDifference(vector<int>& A) {
        for(int i = 0; i < 111; i++) sieve[i] = 0;
        sieve[0] = sieve[1] = 1;
        for(int i = 2; i < 111; i++) {
            if(sieve[i]) continue;
            for(int j = i * i; j < 111; j+=i) sieve[j] = 1;
        }
        int ma = -1, mi = A.size();
        for(int i = 0; i < A.size(); i++) {
            if(sieve[A[i]]) continue;
            ma = max(ma, i);
            mi = min(mi, i);
        }
        return ma - mi;
    }
};