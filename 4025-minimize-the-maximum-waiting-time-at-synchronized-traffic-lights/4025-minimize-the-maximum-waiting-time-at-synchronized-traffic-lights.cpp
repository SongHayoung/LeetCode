class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int ma = *max_element(begin(lights), end(lights));
        int res = 0;
        for(auto& t : arrivalTime) {
            t %= period;
            if(t < ma) continue;
            res = max(res, period - t);
        }
        return res;
    }
};