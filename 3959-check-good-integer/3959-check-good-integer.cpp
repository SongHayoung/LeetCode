class Solution {
public:
    bool checkGoodInteger(int n) {
        int ds = 0, ss = 0;
        while(n) {
            int d = n % 10; n /= 10;
            ds += d, ss += d * d;
        }
        return ss - ds >= 50;
    }
};