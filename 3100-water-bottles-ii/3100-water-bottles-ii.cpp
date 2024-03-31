class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles, e = numBottles, b = 0;
        while(e >= numExchange) {
            e -= numExchange;
            numExchange++;
            e += 1;
            res += 1;
        }
        return res;
    }
};