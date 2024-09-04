class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dir(0), cx(0), cy(0), res(0), dx[4]{0, 1, 0, -1}, dy[4]{1, 0, -1, 0};
        unordered_map<int, unordered_set<int>> o;
        for(auto& _o : obstacles) {
            o[_o[0]].insert(_o[1]);
        }
        
        for(auto& c: commands) {
            if(c == -2) dir = (dir + 3) % 4;
            else if(c == -1) dir = (dir + 1) % 4;
            else {
                while(c--) {
                    int nx = cx + dx[dir];
                    int ny = cy + dy[dir];
                    if(o[nx].count(ny)) break;
                    cx = nx, cy = ny;
                }
                res = max(res, cx * cx + cy * cy);
            }
        }
        
        return res;
    }
};