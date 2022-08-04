class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int y = startPos[0], x = startPos[1];
        vector<pair<int, int>> pos;
        for(auto& ch : s) {
            if(ch == 'U') y--;
            else if(ch == 'D') y++;
            else if(ch == 'L') x--;
            else x++;
            pos.push_back({y,x});
        }
        vector<int> res;
        for(int i = 0; i < pos.size(); i++) {
            for(int j = i; j <= pos.size(); j++) {
                if(j == pos.size()) {
                    res.push_back(j - i);
                    break;
                }
                auto [yy, xx] = pos[j];
                if(0 <= yy and yy < n and 0 <= xx and xx < n) continue;
                res.push_back(j - i);
                break;
            }
            for(int j = i; j < pos.size(); j++) {
                if(s[i] == 'U') pos[j].first++;
                else if(s[i] == 'D') pos[j].first--;
                else if(s[i] == 'L') pos[j].second++;
                else pos[j].second--;
            }
        }
        return res;
    }
};