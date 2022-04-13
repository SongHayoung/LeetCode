/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<pair<int, int>> vec;
        for(auto& intervals : schedule) {
            for(auto& interval : intervals) {
                vec.push_back({interval.start, interval.end});
            }
        }
        sort(vec.begin(),vec.end());
        int ma = vec[0].second;
        vector<Interval> res;
        for(auto& [start, end] : vec) {
            if(start > ma) res.push_back(Interval(ma, start));
            ma = max(ma, end);
        }
        return res;
    }
};