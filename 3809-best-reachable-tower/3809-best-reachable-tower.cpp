
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int best = -1;
        auto ok = [&](int idx) {
            int d = abs(towers[idx][0] - center[0]) + abs(towers[idx][1] - center[1]);
            return d <= radius;
        };
        for(int i = 0; i < towers.size(); i++) {
            if(!ok(i)) continue;
            if(best == -1) best = i;
            else if(towers[best][2] < towers[i][2]) best = i;
            else if(towers[best][2] == towers[i][2] and towers[best] > towers[i]) best = i;
        }
        if(best == -1) return {-1,-1};
        return {towers[best][0],towers[best][1]};
    }
};
