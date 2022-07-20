class Solution {
    bool intersect(int y1, int x1, int r, int y2, int x2) {
        return r * r >= abs(y1 - y2) * abs(y1 - y2) + abs(x1 - x2) * abs(x1 - x2);
    }
    bool inner(int y, int x, int x1, int y1, int x2, int y2) {
        return x1 <= x and x <= x2 and y1 <= y and y <= y2;
    }
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if(inner(yCenter, xCenter, x1, y1, x2, y2)) return true;
        for(int i = x1; i <= x2; i++) {
            if(intersect(yCenter, xCenter, radius, y1, i) or intersect(yCenter, xCenter, radius, y2, i))
                return true;
        }
        for(int i = y1; i <= y2; i++) {
            if(intersect(yCenter, xCenter, radius, i, x1) or intersect(yCenter, xCenter, radius, i, x2))
                return true;
        }
        return false;
    }
};