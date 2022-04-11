class Solution {
public:
    bool judgeSquareSum(int c) {
        long C = c;
        for(long a = 0; a * a <= C; a++) {
            if(C - (a * a) ==  pow((long)sqrt(C - a * a),2)) {
                return true;
            }
        }
        return false;
    }
};
