class Solution {
public:
    vector<long long> minimumRelativeLosses(vector<int>& prices, vector<vector<int>>& queries) {
        sort(begin(prices), end(prices));
        vector<long long> res(queries.size()), pre{0};
        for(int i = 0; i < prices.size(); i++) {
            pre.push_back(pre.back() + prices[i]);
        }
        auto helper = [&](long long l, long long r, long long k, long long cnt) {
            long long res = 1e18;
            long long le = 0, ri = min(cnt,(long long)(upper_bound(prices.begin(), prices.end(), k) - begin(prices)));
            while(le <= ri) {
                long long m = le + (ri - le) / 2, x = (cnt - m);
                long long now = pre[m] + (x ? 2 * k * x - (pre[r+1] - pre[r+1-x]) : 0);
                long long lv = m ? prices[m-1] : 0, rv = x ? 2 * k - prices[r-x+1]:0;
                res = min(res, now);
                if(lv < rv) le = m + 1;
                else if(lv > rv) ri = m - 1;
                else break;
            }
            return res;
        };
        auto query = [&](long long k, long long m) {
            auto p = lower_bound(begin(prices), end(prices), 2 * k) - begin(prices);
            long long cnt = prices.size() - p;
            if(cnt >= m) return 2 * m * k - (pre.back() - pre[prices.size() - m]);
            return 2 * cnt * k - (pre.back() - pre[prices.size() - cnt]) + helper(0,p - 1, k, m - cnt);
        };
        for(int i = 0; i < queries.size(); i++) {
            res[i] = query(queries[i][0], queries[i][1]);
        }
        return res;
    }
};