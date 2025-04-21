class Solution {
public:
    int numberOfArrays(vector<int>& d, int lower, int upper) {
        long minD(min(0, d[0])), maxD(max(0, d[0])), cur(d[0]);
        long rangeDiff = upper - lower, diff = maxD - minD;
        for(int i = 1; i < d.size() && rangeDiff > diff - 1; i++) {
            cur += d[i];
            minD = min(minD, cur);
            maxD = max(maxD, cur);
            diff = maxD - minD;
        }
        return max(upper - lower - maxD + minD + 1, 0L);
    }
};