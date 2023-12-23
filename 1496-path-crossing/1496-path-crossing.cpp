class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>> st;
        int x = 0, y = 0;
        auto move = [&](char p) {
            if(p == 'N') y += 1;
            else if(p == 'S') y -= 1;
            else if(p == 'E') x += 1;
            else if(p == 'W') x -= 1;
        };
        auto ok = [&]() {
            if(st.count({x,y})) return true;
            st.insert({x,y});
            return false;
        };
        ok();
        for(auto& p : path) {
            move(p);
            if(ok()) return true;
        }
        return false;
    }
};