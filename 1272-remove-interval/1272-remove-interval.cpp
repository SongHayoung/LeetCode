class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        
        for(int i = 0, j = 0; i < intervals.size(); i++) {
            if(toBeRemoved[0] <= intervals[i][0] and intervals[i][1] <= toBeRemoved[1]) continue;
            if(toBeRemoved[0] >= intervals[i][1] or toBeRemoved[1] <= intervals[i][0]) {
               res.push_back(intervals[i]);
           } else if(intervals[i][0] <= toBeRemoved[0] and toBeRemoved[1] <= intervals[i][1]) {
               if(intervals[i][0] < toBeRemoved[0])
                   res.push_back({intervals[i][0], toBeRemoved[0]});
               if(toBeRemoved[1] < intervals[i][1])
                   res.push_back({toBeRemoved[1], intervals[i][1]});
            } else if(intervals[i][0] <= toBeRemoved[0]) {
                res.push_back({intervals[i][0], toBeRemoved[0]});
            } else {
                res.push_back({toBeRemoved[1], intervals[i][1]});
            }
        }
        return res;
    }
};