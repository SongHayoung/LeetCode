class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return !z || (x + y >= z && !(z % __gcd(x, y)));
    }
};
