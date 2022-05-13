class Solution {
    int toTime(string& timePoint) {
        auto pos = timePoint.find(':');
        return stoi(timePoint.substr(0,pos)) * 60 + stoi(timePoint.substr(pos + 1));
    }
    int compare(int a, int b) {
        return (b - a + 1440) % 1440;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        for(auto& timePoint : timePoints) {
            times.push_back(toTime(timePoint));
        }
        sort(begin(times), end(times));
        int n = times.size(), res = INT_MAX;
        for(int i = 0; i < n; i++) {
            res = min(res, compare(times[i], times[(i + 1) % n]));
        }
        return res;
    }
};