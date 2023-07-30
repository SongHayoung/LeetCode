class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return true;
        sort(begin(intervals), end(intervals));
        for(int i = 0; i < intervals.size() - 1; i++) {
            if(intervals[i][1] > intervals[i+1][0]) return false;
        }
        return true;
    }
};