class Solution {
public:
    int minFlips(int a, int b, int c) {
        int bit = a | b;
        int res = 0;
        for(int i = 0; i < 32; i++) {
            int ibit = bit & (1<<i), ic = c & (1<<i);
            if(ibit == ic) continue;
            if(ibit) {
                if(a & (1<<i)) res += 1;
                if(b & (1<<i)) res += 1;
            }
            if(ic) res += 1;
        }
        return res;
    }
};