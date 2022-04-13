class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res = 0, ma = values[0] - 1;
        for(int i = 1; i < values.size(); i++, ma--) {
            res = max(res, values[i] + ma);
            ma = max(ma, values[i]);
        }
        return res;
    }
};