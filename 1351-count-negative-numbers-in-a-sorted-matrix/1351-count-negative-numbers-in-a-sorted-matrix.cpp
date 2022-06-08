class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for(auto& r : grid) {
            res += lower_bound(rbegin(r), rend(r), 0) - rbegin(r);
        }
        return res;
    }
};