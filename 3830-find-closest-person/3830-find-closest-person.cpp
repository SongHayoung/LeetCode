class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xz = abs(x-z), yz = abs(y-z);
        return xz < yz ? 1 : xz > yz ? 2 : 0; 
    }
};