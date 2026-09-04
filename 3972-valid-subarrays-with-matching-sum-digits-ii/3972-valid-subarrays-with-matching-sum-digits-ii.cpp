class Solution {
public:
    long long countValidSubarrays(vector<int>& nums, int x) {
        vector<vector<long long>> pos(10);
        pos[0].push_back(0);

        long long pre = 0, res = 0;

        for (int num : nums) {
            pre += num;

            int rem = ((pre - x) % 10 + 10) % 10;
            auto& v = pos[rem];

            for (long long base = 1; ; base *= 10) {
                long long lo = 1LL * x * base;

                __int128 hi128 = (__int128)(x + 1) * base - 1;
                long long hi = hi128 > LLONG_MAX ? LLONG_MAX : (long long)hi128;

                if (lo > pre) break;

                long long left = pre - min(pre, hi);
                long long right = pre - lo;

                auto l = lower_bound(v.begin(), v.end(), left);
                auto r = upper_bound(v.begin(), v.end(), right);

                res += r - l;

                if (base > pre / 10) break;
            }

            pos[pre % 10].push_back(pre);
        }

        return res;
    }
};