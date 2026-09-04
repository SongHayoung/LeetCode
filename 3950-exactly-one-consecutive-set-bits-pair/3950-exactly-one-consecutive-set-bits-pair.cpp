class Solution {
public:
    bool consecutiveSetBits(int n) {
        int ok = 0;
        while(n) {
            if((n & 3) == 3) ok++;
            n /= 2;
        }
        return ok == 1;
    }
};