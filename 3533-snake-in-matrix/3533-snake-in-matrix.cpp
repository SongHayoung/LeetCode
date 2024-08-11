class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int y = 0, x = 0;
        map<char,pair<int,int>> dir{{'U',{-1,0}},{'D',{1,0}},{'R',{0,1}},{'L',{0,-1}}};
        for(auto& c : commands) {
            auto [yy,xx] = dir[c[0]];
            y += yy, x += xx;
        }
        int res = y * n + x;
        for(int i = 0; i < commands.size(); i++) {
            for(auto& c : commands) {
            auto [yy,xx] = dir[c[0]];
            y += yy, x += xx;
        }
        }
        return res;
    }
};