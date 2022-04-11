class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t lb = 1<<31, rb = 1;
        for(int i = 0; i < 16; i++, lb>>=1, rb<<=1) {
            bool left = lb & n;
            bool right = rb & n;
            if(left != right) {
                n ^= lb ^ rb;
            }
        }
        return n;
    }
};