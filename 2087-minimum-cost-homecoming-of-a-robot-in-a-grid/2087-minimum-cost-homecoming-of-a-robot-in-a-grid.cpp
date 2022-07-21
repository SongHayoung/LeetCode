class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int y = startPos[0], x = startPos[1], gy = homePos[0], gx = homePos[1];
        int res = 0;
        if(y > gy) for(int i = y - 1; i >= gy; i--) res += rowCosts[i];
        else for(int i = y + 1; i <= gy; i++) res += rowCosts[i];
        if(x > gx) for(int i = x - 1; i >= gx; i--) res += colCosts[i];
        else for(int i = x + 1; i <= gx; i++) res += colCosts[i];
        return res;
    }
};