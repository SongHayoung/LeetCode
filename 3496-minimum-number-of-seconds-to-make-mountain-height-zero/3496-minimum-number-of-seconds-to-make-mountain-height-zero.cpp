
class Solution {
    bool helper(int mountainHeight, long long k, vector<int>& workerTimes) {
        for(auto& t : workerTimes) {
            long long x = t, lim = k;
            while(mountainHeight and lim >= x) {
                lim -= x;
                mountainHeight--;
                x += t;
            }
            if(mountainHeight == 0) return true;
        }
        return false;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        sort(begin(workerTimes), end(workerTimes));
        long long l = 0, r = 1e18, res = r;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = helper(mountainHeight, m, workerTimes);
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};