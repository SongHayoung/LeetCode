
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int x = abs(sx - fx);
        int y = abs(sy - fy);
        if(max(x,y) > t) return false;
        if(t >= 2) return true;
        if(t == 0) return x == 0 and y == 0;
        if(t == 1) return max(x,y) == 1;
        return true;
    }
};
