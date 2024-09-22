class Solution {
    long long helper(long long n) {
        if(n < 1) return 0;
        double x = (-1.0 + sqrt(1.0 + 8.0 * n)) / 2.0;
        long long res = static_cast<long long>(floor(x));
        return max(res,1ll);
    }
    bool helper(int mountainHeight, long long k, vector<int>& workerTimes) {
        for(auto& t : workerTimes) {
            mountainHeight -= helper(k / t);
            if(mountainHeight <= 0) return true;
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
