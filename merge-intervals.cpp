class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res{{intervals[0].front(), intervals[0].back()}};
        for(auto& vec : intervals) {
            if(vec.front() > res.back().back()) res.push_back(vec);
            else res.back()[1] = max(res.back().back(), vec.back());
        }
        return res;
    }
};
