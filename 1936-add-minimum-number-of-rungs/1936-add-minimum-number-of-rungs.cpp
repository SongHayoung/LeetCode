class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int res = 0, now = 0;
        for(auto& r : rungs) {
            if(r - now > dist) {
                res += (r - now - 1) / dist;
            }
            now = r;
        }
        return res;
    }
};