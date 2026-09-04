class Solution {
    static constexpr long long INF = 1LL << 60;
    long long helper(const vector<long long>& cost, int start, int len, int need) {
        if (need < 0) return INF;
        if (need == 0) return 0;
        if (len <= 0) return INF;
        if (need > (len + 1) / 2) return INF;

        vector<long long> prev2(need + 1, INF), prev1(need + 1, INF), cur;
        prev2[0] = 0;
        prev1[0] = 0;

        for (int i = 0; i < len; i++) {
            cur = prev1;
            long long w = cost[start + i];
            for (int j = 1; j <= need; j++) {
                if (prev2[j - 1] != INF) {
                    cur[j] = min(cur[j], prev2[j - 1] + w);
                }
            }
            prev2.swap(prev1);
            prev1.swap(cur);
        }

        return prev1[need];
    }

public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 0) return 0;
        if (k > n / 2) return -1;

        vector<long long> cost(n);
        for (int i = 0; i < n; i++) {
            cost[i] = max({0, nums[(i - 1 + n) % n] - nums[i] + 1, nums[(i + 1) % n] - nums[i] + 1});
        }

        long long res = min(helper(cost, 1, n - 1, k), cost[0] + helper(cost, 2, max(0, n - 3), k - 1));
        return res == INF ? -1 : res;
    }
};