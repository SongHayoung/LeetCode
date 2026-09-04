
class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long b = brightness / 3 + (brightness % 3 ? 1 : 0), res = 0;
        sort(rbegin(intervals), rend(intervals));
        while(intervals.size()) {
            int e = intervals.back()[1], s = intervals.back()[0];
            while(intervals.size() and intervals.back()[0] <= e) {
                e = max(intervals.back()[1], e);
                intervals.pop_back();
            }
            res  += (e - s + 1) * b;
        }
        return res;
    }
};