class Solution {
public:
    int getSum(int a, int b) {
        int upper = 0;
        int res = 0;
        for(int i = 0; i < 32 and (a or b); i++) {
            int bit = 1<<i;
            if(upper) {
                if(a & bit and b & bit) res |= bit;
                else if(!(a & bit) and !(b & bit)) {res |= bit; upper = 0;}
            } else {
                if(a & bit and b & bit) upper = 1;
                else if(a & bit or b & bit) res |= bit;
            }
            a ^= bit;
            b ^= bit;
        }
        return res;
    }
};