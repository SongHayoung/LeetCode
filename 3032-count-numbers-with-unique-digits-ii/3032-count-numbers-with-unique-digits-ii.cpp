class Solution {
    bool ok(int x) {
        int bit = 0;
        while(x) {
            int k = x % 10;
            if(bit & 1ll<<k) return false;
            bit ^= (1ll<<k);
            x /= 10;
        }
        return true;
    }
public:
    int numberCount(int a, int b) {
        int res = 0;
        for(int i = a; i <= b; i++) if(ok(i)) res++;
        return res;
    }
};