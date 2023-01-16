class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()) {
            return vector<vector<int>>{newInterval};
        } else if(intervals.front()[0] > newInterval[1]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        } else if(intervals.back()[1] < newInterval[0]) {
            intervals.push_back(newInterval);
            return intervals;
        }

        int startPos = intervals.size() - 1, endPos = intervals.size() - 1;
        for(int i = 0; i < intervals.size(); i++) {
            if(intervals[i][1] >= newInterval[0]) {
                startPos = min(startPos, i);
            }

            if(intervals[i][0] > newInterval[1]) {
                endPos = min(endPos, i - 1);
                break;
            }
        }

        intervals.insert(intervals.begin() + startPos, vector<int>{min(intervals[startPos][0], newInterval[0]), max(intervals[endPos][1], newInterval[1])});
        intervals.erase(intervals.begin() + startPos + 1, intervals.begin() + endPos + 2);

        return intervals;
    }
};