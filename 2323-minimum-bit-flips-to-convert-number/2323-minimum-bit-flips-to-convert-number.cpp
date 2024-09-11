class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = 0;
        for(int i = 0; i <= 31; i++) {
            int s = start & (1<<i);
            int g = goal & (1<<i);
            if(s != g) res++;
        }
        return res;
    }
};
