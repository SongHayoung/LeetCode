class Solution {
public:
    int maxDistance(string moves) {
        int y = 0, x = 0, any = 0;
        for(auto& m : moves) {
            if(m == 'U') y++;
            if(m == 'D') y--;
            if(m == 'L') x++;
            if(m == 'R') x--;
            if(m == '_') any++;
        }
        return abs(y) + abs(x) + any;
    }
};