/**
 * Definition of commonBits API.
 * int commonBits(int num);
 */

class Solution {
public:
    int findNumber() {
        int res = 0, zero = commonBits(0);
        for(int i = 0; i < 31; i++) {
            if(commonBits(1ll<<i) > zero) {
                zero++;
                res |= 1ll<<i;
            } else {
                commonBits(1ll<<i);
            }
        }
        return res;
    }
};