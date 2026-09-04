
class Solution {
    pair<long long, int> helper(vector<int>& nums, vector<long long>& pre, long long m, long long l, long long r,long long cost) {
        int n = nums.size();
        vector<long long> dp(n + 1);
        vector<int> cnt(n + 1);
        deque<int> dq;

        auto val = [&](int i) {
            return dp[i] - pre[i];
        };

        auto bad = [&](int a, int b) {
            long long va = val(a);
            long long vb = val(b);

            if (va != vb) return va < vb;
            return cnt[a] <= cnt[b];
        };

        for (int i = l; i <= n; i++) {
            int add = i - l;

                while (!dq.empty() and bad(dq.back(), add)) dq.pop_back();
                dq.push_back(add);

            while (!dq.empty() && dq.front() < i - r) dq.pop_front();

            dp[i] = dp[i - 1];
            cnt[i] = cnt[i - 1];

            if (!dq.empty()) {
                long long take = val(dq.front()) + pre[i] - cost;
                int takeCnt = cnt[dq.front()] + 1;

                if (take > dp[i] or (take == dp[i] and takeCnt > cnt[i])) {
                    dp[i] = take;
                    cnt[i] = takeCnt;
                }
            }
        }

        return {dp[n], cnt[n]};
    }
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        long long n = nums.size(), res = LLONG_MIN;
        vector<long long> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        {
            multiset<long long> ms;
            for(int i = n - l; i >= 0; i--) {
                ms.insert(pre[i+l]);
                res = max(res, *prev(end(ms)) - pre[i]);
                if(i + r <= n) ms.erase(ms.find(pre[i+r]));
            }
        }
        auto zero = helper(nums, pre, m, l, r, 0);
        if(!zero.second) return res;
        if(zero.second <= m) return zero.first;
        long long le = 0, ri = 1e18;
        while (le <= ri) {
    long long mid = le + (ri - le) / 2;
    auto [v, c] = helper(nums, pre, m, l, r, mid);

    if (c > m) {
        le = mid + 1;
    } else {
        ri = mid - 1;
    }
}

auto [v, c] = helper(nums, pre, m, l, r, ri);

return v + ri * 1LL * m;
    }
};