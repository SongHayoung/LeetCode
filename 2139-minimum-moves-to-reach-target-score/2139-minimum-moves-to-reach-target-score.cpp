class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int res = 0;
        while(target != 1) {
            if(target & 1) target--;
            else {
                if(maxDoubles) {
                    target /= 2;
                    maxDoubles--;
                } else return target - 1 + res;
            }
            res++;
        }
        return res;
    }
};