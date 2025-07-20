long long binom[64][64];
long long nCr(long long n, long long r) {
    if (r < 0 || r > n || n >= 64) return 0;
    if (r == 0 || r == n) return 1;
    if (binom[n][r] != 0) return binom[n][r];
    return binom[n][r] = nCr(n-1, r-1) + nCr(n-1, r);
}
class Solution {
    int countDepth(int numberOfBits) {
        int res = 1;
        while(numberOfBits > 1) {
            numberOfBits = __builtin_popcount(numberOfBits);
            res++;
        }
        return res;
    }
    long long helper(long long n, vector<int>& bits, long long usedBits, long long shift, bool less) {
        if(shift == -1) {
            // check n is k-popcountDepth
            for(auto& bit : bits) if(bit == usedBits) return 1;
            return false;
        }
        if(less) {
            // case if current built value is less then n
            long long res = 0;
            for(auto& bit : bits) {
                if(bit < usedBits) continue;
                res += nCr(shift + 1, bit - usedBits);
            }
            return res;
        }
        if((n & (1ll<<shift)) == 0) {
            // case if n's shift_th bit is off
            return helper(n,bits,usedBits,shift - 1, false);
        }
        // case if n's shift_th bit is on
        long long res = helper(n,bits,usedBits, shift - 1, true);
        res += helper(n, bits, usedBits + 1, shift - 1, false);
        return res;
    }
public:
    long long popcountDepth(long long n, int k) {
        if(k == 0) return 1;
        vector<int> depth(64);
        for(int numberOfBits = 1; numberOfBits < 64; numberOfBits++) {
            depth[numberOfBits] = countDepth(numberOfBits);
        }
        vector<int> bits;
        for(int i = 1; i < 64; i++) if(depth[i] == k) bits.push_back(i);
        long long res = helper(n,bits,0,63,false);
        // cause 1 is not 1 popcountDepth
        if(k == 1) res--;
        return res;
    }
};