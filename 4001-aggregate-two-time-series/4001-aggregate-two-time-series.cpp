class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        reverse(begin(series1), end(series1));
        reverse(begin(series2), end(series2));
        vector<vector<int>> res;
        while(series1.size() or series2.size()) {
            int t = INT_MAX, c = 0;
            if(series1.size()) {
                t = min(t, series1.back()[0]);
                c += series1.back()[1];
            }
            if(series2.size()) {
                t = min(t, series2.back()[0]);
                c += series2.back()[1];
            }
            res.push_back({t,c});
            if(series1.size() and series1.back()[0] == t) series1.pop_back();
            if(series2.size() and series2.back()[0] == t) series2.pop_back();
        }
        return res;
    }
};