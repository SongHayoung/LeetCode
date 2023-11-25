class Solution {
public:
    int findMaximumLength(vector<int>& A) {
        A.insert(begin(A), 0);
        long long sum = 0, now = 0, res = 0, n = A.size();
        vector<pair<long long, long long>> dp(n + 100, {-1,-1});
        vector<long long> pre{0};
        for(int i = 1; i < n; i++) pre.push_back(pre.back() + A[i]);
        pre.push_back(1e15);
        dp[0] = {0,0};
        dp[1] = {A[1], 1};
        auto cmp = [&](pair<long long, long long> now, int pos) {
            if(dp[pos].second == -1) dp[pos] = now;
            else if(dp[pos].second < now.second) dp[pos] = now;
            else if(dp[pos].second == now.second) dp[pos] = min(dp[pos], now);
        };
        for(int i = 1; i < n; i++) {
            cmp({dp[i-1].first + A[i], dp[i-1].second}, i);
            long long target = dp[i].first + pre[i];
            int p = std::lower_bound(pre.begin(), pre.end(),target) - begin(pre);
            if(p < n) {
                long long sum = pre[p] - pre[i];
                cmp({sum, dp[i].second + 1}, p);
            }
            res = max(res, dp[i].second);
        }
        return res;
    }
};
