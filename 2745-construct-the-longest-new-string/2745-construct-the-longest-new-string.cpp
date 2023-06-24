class Solution {
public:
    int longestString(int x, int y, int z) {
        int mi = min(x,y);
        x -= mi, y -= mi;
        mi = mi * 2 + z;
        mi += (x > 0 or y > 0);
        return mi * 2;
    }
};