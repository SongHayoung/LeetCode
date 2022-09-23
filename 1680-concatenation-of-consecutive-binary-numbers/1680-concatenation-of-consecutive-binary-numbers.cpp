class Solution {
    int mod = 1e9 + 7;
public:
    int concatenatedBinary(int n) {
        long res = 0, shift = 0;
        for(int i = 1; i <= n; i++) {
            if((i & (i-1)) == 0) shift++;
            res = ((res<<shift) % mod + i) % mod;
        }
        return res;
    }
};