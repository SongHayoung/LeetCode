class Solution {
public:
    long long maximumTotalDamage(vector<int>& A) {
        sort(rbegin(A), rend(A));
        map<long long, long long> dp;
        long long res = 0, best = 0;
        while(A.size()) {
            long long now = 0, x = A.back();
            while(A.size() and A.back() == x) {
                now += x;
                A.pop_back();
            }
            while(dp.size() and begin(dp)->first < x - 2) {
                best = max(best, begin(dp)->second);
                dp.erase(begin(dp));
            }
            dp[x] = max(dp[x], best + now);
            res = max(res, dp[x]);
        }
        return res;
    }
};
