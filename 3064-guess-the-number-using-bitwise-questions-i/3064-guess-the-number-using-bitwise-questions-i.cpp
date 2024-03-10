/** 
 * Definition of commonSetBits API.
 * int commonSetBits(int num);
 */

class Solution {
public:
    int findNumber() {
        int res = 0, bit = 1;
        for(int i = 0; i < 32; i++) {
            if(commonSetBits(bit)) res |= bit;
            bit<<=1;
        }
        return res;
    }
};