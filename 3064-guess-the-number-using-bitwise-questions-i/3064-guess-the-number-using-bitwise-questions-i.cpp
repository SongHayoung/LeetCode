/** 
 * Definition of commonSetBits API.
 * int commonSetBits(int num);
 */

class Solution {
public:
    int findNumber() {
        int cnt = commonSetBits((1<<30) - 1), res = 0;
        for(int i = 0; i < 30; i++) {
            if(cnt != commonSetBits(((1<<30) - 1) ^ (1<<i))) res ^= 1<<i;
        }
        return res;
    }
};