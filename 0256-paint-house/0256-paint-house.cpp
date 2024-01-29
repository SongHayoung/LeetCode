class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int r = 0, g = 0, b = 0;
        for(auto& c : costs) {
            int R = c[0], G = c[1], B = c[2];
            int nr = min(g,b) + R, ng = min(r,b) + G, nb = min(r,g) + B;
            r = nr, g = ng, b = nb;
        }
        return min({r,g,b});
    }
};