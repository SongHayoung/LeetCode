class Solution {
    int d(int x) {
        int res = 0;
        while(x) {
            res += x % 10; x /= 10;
        }
        return res;
    }
public:
    int countBalls(int lowLimit, int highLimit) {
        int res = 0;
        vector<int> buc(55);
        for(int i = lowLimit; i <= highLimit; i++) {
            res = max(res, ++buc[d(i)]);
        }
        return res;
    }
};