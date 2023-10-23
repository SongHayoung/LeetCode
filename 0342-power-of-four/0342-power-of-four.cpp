class Solution {
    //4^0 + 4^1 + 4^2 .... + 4^15
    const int bit = 1431655765;
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        bitset<32> bi(n);
        return (bit & n) == n and bi.count() == 1;
    }
};