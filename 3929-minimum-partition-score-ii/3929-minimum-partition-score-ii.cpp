
struct Line {
    long long m, b;
    int cnt;

    long long get(long long x) const {
        return m * x + b;
    }
};

bool bad(const Line& a, const Line& b, const Line& c) {
    return (__int128)(b.b - a.b) * (b.m - c.m)
           > (__int128)(c.b - b.b) * (a.m - b.m);
}
class Solution {

    pair<long long, int> helper(const vector<long long>& pre, long long lambda) {
        int n = pre.size() - 1;

        deque<Line> q;

        vector<long long> dp(n + 1);
        vector<int> cnt(n + 1);

        q.push_back({0,0,0});

        for(int i = 1; i <= n; i++) {
            long long x = pre[i];

            while(q.size() >= 2) {
                long long v1 = q[0].get(x);
                long long v2 = q[1].get(x);

                if(v2 < v1 or (v2 == v1 and q[1].cnt > q[0].cnt))
                    q.pop_front();
                else
                    break;
            }

            auto cur = q.front();

            dp[i] = x * x + x + cur.get(x) + 2 * lambda;

            cnt[i] = cur.cnt + 1;

            Line nl = {-2 * x,dp[i] + x * x - x,cnt[i]};

            while(q.size() >= 2 and bad(q[q.size() - 2], q.back(), nl)) q.pop_back();

            q.push_back(nl);
        }

        return {dp[n], cnt[n]};
    }

public:
    long long minPartitionScore(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> pre(n + 1);
        for(int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

        long long l = 0;
        long long r = pre[n] * pre[n];

        while(l <= r) {
            long long m = l + (r - l) / 2;

            auto [cost, parts] = helper(pre, m);

            if(parts >= k)
                l = m + 1;
            else
                r = m - 1;
        }

        auto [cost, parts] = helper(pre, r);

        return cost / 2 - r * k;
    }
};
