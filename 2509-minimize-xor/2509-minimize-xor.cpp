class Solution {
    bool bit(int x, int p) {
        return (x>>p) & 1;
    }
public:
    int minimizeXor(int num1, int num2) {
        int pc = __builtin_popcount(num2);
        int res = 0;
        for(int i = 31; i >= 0 and pc; i--) {
            if(bit(num1,i)) {
                pc--;
                res ^= 1<<i;
            }
        }
        for(int i = 0; i < 32 and pc; i++) {
            if(bit(num1,i)) continue;
            pc--;
            res ^= 1<<i;
        }
        return res;
    }
};