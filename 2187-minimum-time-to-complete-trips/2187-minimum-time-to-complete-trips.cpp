class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        sort(time.begin(), time.end());
        long long l = 1, r = LLONG_MAX;
        long long res = LLONG_MAX;
        while(l <= r) {
            long long sum = 0;
            long long m = l + (r- l) / 2; //target time;
            for(auto t : time) {
                sum += m / t;
                if(sum >= totalTrips) break;
            }
            if(sum >= totalTrips) {
                res = min(res, m);
                r = m - 1;
            } else {
                l = m + 1; 
            }
        }
        return res;
    }
};