class Solution {
    unordered_map<int, set<int>> pos;
public:
    int minAreaRect(vector<vector<int>>& po) {
        int res = INT_MAX;
        for(auto& p : po) {
            pos[p[0]].insert(p[1]);
        }
        
        for(int i = 0; i < po.size(); i++) {
            for(int j = i + 1; j < po.size(); j++) {
                if(po[i][0] == po[j][0] || po[i][1] == po[j][1]) continue;
                int area = abs(po[j][0] - po[i][0]) * abs(po[j][1] - po[i][1]);
                if(area >= res) continue;
                if(pos[po[i][0]].count(po[j][1]) and pos[po[j][0]].count(po[i][1])) res = area;
                
            }
        }
        
        return res == INT_MAX ? 0 : res;
    }
};