class Solution {
public:
    vector<vector<int>> findMaximalUncoveredRanges(int n, vector<vector<int>>& ranges) {
        ranges.push_back({n,n});
        ranges.push_back({-1,-1});
        sort(rbegin(ranges), rend(ranges));
        vector<vector<int>> res;
        while(ranges.size()) {
            int x = ranges.back()[1];
            while(ranges.size() and ranges.back()[0] <= x + 1) {
                x = max(x, ranges.back()[1]);
                ranges.pop_back();
            }
            if(ranges.size()) res.push_back({x+1,ranges.back()[0] - 1});
        }
        return res;
    }
};